#pragma once
#include "Shoes.h"

class Factory
{
public:
	virtual ~Factory() {}
	virtual Shoes* CreateShoes() = 0;
};

class NikeFactory : public Factory
{
public:
	Shoes* CreateShoes()
	{
		return new NiKeShoes();
	}
};

class AdidasFactory : public Factory
{
public:
	Shoes* CreateShoes()
	{
		return new AdidasShoes();
	}
};

class LiNingFactory : public Factory
{
public:
	Shoes* CreateShoes()
	{
		return new LiNingShoes();
	}
};