#pragma once
#include <iostream>
#include <mutex>

using namespace std;

class Singleton
{
public:
	static Singleton* getInstance();

private:
	Singleton();
	~Singleton();

	class Delete
	{
	public:
		Delete() {};
		~Delete();
	};
	static Delete m_deleter;
private:
	static Singleton* instance;
	static mutex m_mutex;
	
};