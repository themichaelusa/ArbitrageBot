#ifndef BITFINEX_H
#define BITFINEX_H

#include "ExchangeAPI.h"

namespace Exchange{
	class Bitfinex_API: public ExchangeAPI{
		public:
			Bitfinex_API();
			~Bitfinex_API();
	};
}

#endif