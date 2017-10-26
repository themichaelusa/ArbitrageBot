#include "Bot.h"
#include "Position/Position.h"
#include "ExchangeAPI/ExchangeWrapper.h"

#include <string>
#include <utility> 
#include <fstream>
#include <iostream>
#include <ctime>

Bot::Bot(std::string exchange1, std::string exchange2, double quantity){
	ExchangeWrapper wrapper;
	ex1_ = wrapper(exchange1, quantity); 
	ex2_ = wrapper(exchange2, quantity); 
	quantity_ = quantity;
}

Bot::~Bot(){
	delete ex1_; ex1_ = nullptr;
	delete ex2_; ex2_ = nullptr;
}

void Bot::startBot(long endTime){

    while(std::time(nullptr) < endTime){
		std::pair<Position, bool> potentialArb = tryArbitrage();
		if (std::get<1>(potentialArb) == true){
			writeToTextFile(tradeData);
		} 
    }
}

void Bot::startBot(int numTrades){

	int totalTrades = 0;
    while(totalTrades < numTrades){
		std::pair<Position, bool> potentialArb = tryArbitrage();
		if (std::get<1>(potentialArb) == true){
			writeToTextFile(tradeData);
			totalTrades++;   
		} 
    }
}

std::pair<Position, bool> Bot::tryArbitrage(){
		
	double e1Spot = ex1_->getSpotPrice();
	double e2Spot = ex2_->getSpotPrice();

	if(isProfitableSpread(e1Spot, e2Spot)){
		Position tradeData = executeArbitrage(e1Spot, e2Spot);
		tradeData.completionTime = std::time(nullptr);

		//TODO: Check API's for complete position and that funds are settled
		tradeData.isComplete = true;
		return std::pair<Position, bool> p(tradeData, true);
	}
	else {
		return std::pair<Position, bool> p(Position(), false);
	}
}

void Bot::writeToTextFile(Position p){
	std::string pos = "";
	pos += ((std:string)p.q + ",");
	pos += ((std:string)p.sP + ",");
	pos += ((std:string)p.lP + ",");
	pos += ((std:string)p.completionTime + "\n");

	std::cin >> pos;
    std::ofstream out("closedPositions.txt");
    out << pos;
}

Position Bot::executeArbitrage(double spot1, double spot2){
	//TODO: IMPLEMENT ARBITRAGE
	ex1_->goLong(); ex2_->goShort();
	return Position(quantity_, spot1, spot2);
}

bool Bot::isProfitableSpread(double spot1, double spot2){

	//TODO: Include additional parameters beyond just ROI
	double e1Commission = ex1_->getCommission();
	double e2Commission = ex2_->getCommission();
	double spread = spot1-spot2;
	double adjSpread = spread-(spread*(e1Commission+e2Commission));

	if (adjSpread > 0){
		return true;
	}
	return false;
}

