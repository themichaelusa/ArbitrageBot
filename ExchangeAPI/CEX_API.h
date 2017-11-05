#ifndef CEX_H
#define CEX_H

#include "ExchangeAPI.h"

class CEX_API: public ExchangeAPI{
	public:
		CEX_API(double quantity);
		~CEX_API();
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