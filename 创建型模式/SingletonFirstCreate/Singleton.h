#pragma once
#include <iostream>

using namespace std;

class Singleton
{
public:
	static shared_ptr<Singleton> getInstance();
	static void destoryInstance(Singleton* x);
private:
	Singleton();
	~Singleton();

	static shared_ptr<Singleton> instance;
};