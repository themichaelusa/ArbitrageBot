#ifndef POSITION_H
#define POSITION_H

#include <ctime>

struct Position {
	double q;
	double sP;
	double lP;
	std::time_t completionTime;
	bool isComplete;

	Position() {}
	Position(double quantity, double shortPrice, double longPrice): 
		q(quantity), sP(shortPrice), lP(longPrice) {}
};

#endif
