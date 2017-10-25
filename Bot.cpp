#include "Bot.h"
#include "Position/Position.h"
#include <string>
#include <utility> 
#include<ctime>

Bot::Bot(std::string exchange1, std::string exchange2){
	std::ex1_ = exchange1;
	std::ex2_ = exchange2;
}

void Bot::startBot(long endTime){

    while(time(nullptr) < endTime){
		std::pair<Position, bool> potentialArb = tryArbitrage();
		if (std::get<1>(potentialArb) == true){
			writeToTXT(tradeData);
		} 
    }
}

void Bot::startBot(int numTrades){

	int totalTrades = 0;
    while(totalTrades < numTrades){
		std::pair<Position, bool> potentialArb = tryArbitrage();
		if (std::get<1>(potentialArb) == true){
			writeToTXT(tradeData);
			totalTrades++;   
		} 
    }
}

std::pair<Position, bool> Bot::tryArbitrage(){
	double spread = getExchangeSpread();
	if(isProfitableSpread(spread)){
		Position tradeData = executeArbitrage();
		tradeData.completionTime = time(nullptr);

		//TODO: Check API's for complete position
		tradeData.isComplete = true;
		return std::pair<Position, bool> p(tradeData, true);
	}

	return std::pair<Position, bool> p(Position(), false);
}

void Bot::writeToTXT(Position p){
	return;
}

Position Bot::executeArbitrage(){
	return Position(0, 0, 0);
}

double Bot::getExchangeSpread(){
	return 0.0;
}

bool Bot::isProfitableSpread(double spread){

	//TODO: Include additional parameters beyond just ROI
	if (spread > 0){
		return true;
	}
	return false;
}

