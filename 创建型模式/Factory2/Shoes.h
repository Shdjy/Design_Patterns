#pragma once
#include <iostream>

using namespace std;

class Shoes
{
public:
	virtual ~Shoes() {}
	virtual void Show() = 0;

};

class NiKeShoes : public Shoes
{
	void Show()
	{
		cout << "耐克鞋子" << endl;
	}
};

class AdidasShoes : public Shoes
{
	void Show()
	{
		cout << "阿迪鞋子" << endl;
	}
};

class LiNingShoes : public Shoes
{
	void Show()
	{
		cout << "李宁鞋子" << endl;
	}
};