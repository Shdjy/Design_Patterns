#include "Singleton.h"

shared_ptr<Singleton> Singleton::getInstance()
{
	lock_guard<mutex> l(m_mutex);
	if (instance == nullptr)
	{

		cout << "实例为空，创建！" << endl;
		instance.reset(new Singleton(), destoryInstance);
		cout << "地址是" << instance << endl;
		cout << "创建结束" << endl;
	}
	else
	{
		cout << "已有实例，返回！" << endl;
	}
	return instance;
}

void Singleton::destoryInstance(Singleton* x)
{
	cout << "自定义释放实例。" << endl;
	delete x;
}

Singleton::Singleton()
{
	cout << "调用构造函数." << endl;
}

Singleton::~Singleton()
{
	cout << "调用析构函数。" << endl;
}
