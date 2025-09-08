#pragma once
#include <iostream>

using namespace std;
class Shoes
{
public:
	virtual ~Shoes() {};
	virtual void Show() = 0;
};

class NikeShoes : public Shoes
{
public:
	NikeShoes() {};
	void Show()
	{
		cout << "NIKE鞋子" << endl;
	}
};

class AdidasShoes : public Shoes
{
public:
	void Show()
	{
		cout << "adidas鞋子" << endl;
	}
};

class LiNingShoes : public Shoes
{
public:
	void Show()
	{
		cout << "李宁鞋子" << endl;
	}
};