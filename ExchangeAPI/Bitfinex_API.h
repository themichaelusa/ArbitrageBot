#ifndef BITFINEX_H
#define BITFINEX_H

#include "ExchangeAPI.h"

class Bitfinex_API: public ExchangeAPI{
	public:
		Bitfinex_API(double quantity);
		~Bitfinex_API();

		void updateCommission();
		double getSpotPrice();
		void goShort();
		void goLong();

	protected:
		void setKey();
		void setNonce();
		void setSignature();
};

#endif