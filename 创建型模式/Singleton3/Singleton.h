#pragma once
#include <iostream>
#include <mutex>

using namespace std;

class Singleton
{
public:
	static Singleton& getInstance();


private:
	Singleton();
	~Singleton();
};