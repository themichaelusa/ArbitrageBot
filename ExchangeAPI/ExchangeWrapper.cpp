#include "ExchangeWrapper.h"
#include "ExchangeAPI.h"
#include "Bitfinex_API.h"
#include "CEX_API.h"
#include <string>

ExchangeWrapper::ExchangeWrapper(){}
ExchangeWrapper::~ExchangeWrapper(){}

ExchangeAPI* ExchangeWrapper::operator()(std::string s, double quantity) const {
	if (s == "BFX"){
		return new Bitfinex_API(quantity);
	}
	if (s == "CEX"){
		return new CEX_API(quantity);
	}
}