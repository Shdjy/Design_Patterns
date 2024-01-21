#pragma once

#include "Shoes.h"


enum SHOES_TYPE
{
	NIKE,
	ADIDASI,
	LINING
};

class Factory
{
public:
	Shoes* CreateShoes(SHOES_TYPE type)
	{
		switch (type)
		{
		case NIKE:
			return new NikeShoes();
			break;
		case ADIDASI:
			return new AdidasShoes();
			break;
		case LINING:
			return new LiNingShoes();
			break;
		default:
			break;
		}
	}
};
