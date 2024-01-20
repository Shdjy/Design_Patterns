#pragma once
#include <iostream>

using namespace std;

class Singleton
{
public:
	static Singleton* getInstance();

	class Delete
	{
	public:
		Delete();
		~Delete();
	};
	static Delete m_deleter;
private:
	Singleton();
	~Singleton();

	static Singleton* instance;
	

};