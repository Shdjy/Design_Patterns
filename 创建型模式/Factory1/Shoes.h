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
		cout << "NIKEЬ��" << endl;
	}
};

class AdidasShoes : public Shoes
{
public:
	void Show()
	{
		cout << "adidasЬ��" << endl;
	}
};

class LiNingShoes : public Shoes
{
public:
	void Show()
	{
		cout << "����Ь��" << endl;
	}
};