#ifndef CEX_H
#define CEX_H

#include "ExchangeAPI.h"

namespace Exchange{
	class CEX_API: public ExchangeAPI{
		public:
			CEX_API();
			~CEX_API();
	};
}

#endif