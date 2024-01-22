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
		cout << "�Ϳ�Ь��" << endl;
	}
};

class AdidasShoes : public Shoes
{
	void Show()
	{
		cout << "����Ь��" << endl;
	}
};

class LiNingShoes : public Shoes
{
	void Show()
	{
		cout << "����Ь��" << endl;
	}
};