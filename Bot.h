#ifndef BOT_H
#define BOT_H

#include "Position/Position.h"
#include <utility> 
#include <string>

class Bot {
	public:
		Bot(std::string exchange1, std::string exchange2);
		void startBot(long endTime);
		void startBot(int numTrades);

	private:	

		std::string ex1_;
		std::string ex2_;

		double getExchangeSpread();
		bool isProfitableSpread();
		std::pair<Position, bool> tryArbitrage();
		Position executeArbitrage();
		void writeToTXT(Position p);
};

#endif