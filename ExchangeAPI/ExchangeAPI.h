#ifndef EXCHANGE_H
#define EXCHANGE_H

#include <string>

class ExchangeAPI{
	public:
		ExchangeAPI();
		virtual ~ExchangeAPI();
		virtual double getQuantity();
		virtual double getCommission();
		
		virtual double getSpotPrice() = 0;
		virtual void goShort() = 0;
		virtual void goLong() = 0;

	protected:
		//ACCESS METHODS GO HERE
		virtual void setKey() = 0;
		virtual void setNonce() = 0;
		virtual void setSignature() = 0;

		double commission_;
		double quantity_;
		
		//KEYS GO HERE
		std::string apikey_;
		std::string nonce_;
		std::string signature_;

};

#endif

