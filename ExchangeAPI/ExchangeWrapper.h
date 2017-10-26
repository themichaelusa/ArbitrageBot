#ifndef EXCWRAPPER_H
#define EXCWRAPPER_H

#include <string>
#include "ExchangeAPI.h"

class ExchangeWrapper {
public:
	ExchangeWrapper();
	~ExchangeWrapper();
	ExchangeAPI* operator()(std::string s, double quantity) const;
};

#endif