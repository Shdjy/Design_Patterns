#pragma once

#include <iostream>
#include <mutex>
#include <memory>
using namespace std;

class Singleton
{
public:
	static shared_ptr<Singleton> getInstance();
	static void destoryInstance(Singleton* x);
private:
	Singleton();
	~Singleton();

private:
	static shared_ptr<Singleton> instance;
	static mutex m_mutex;//线程安全
};


