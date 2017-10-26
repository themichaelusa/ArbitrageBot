#ifndef BOT_H
#define BOT_H

#include "Position/Position.h"
#include "ExchangeAPI/ExchangeAPI.h"
#include <utility> 
#include <string>

class Bot {
	public:
		Bot(std::string exchange1, std::string exchange2, double quantity);
		~Bot();
		void startBot(long endTime);
		void startBot(int numTrades);

	private:	
		ExchangeAPI* ex1_; //LONG EXCHANGE
		ExchangeAPI* ex2_; //SHORT EXCHANGE
		double quantity_;

		bool isProfitableSpread(double spot1, double spot2);
		std::pair<Position, bool> tryArbitrage();
		Position executeArbitrage(double spot1, double spot2);
		void writeToTextFile(Position p);
};

#endif