#include "Singleton.h"


Singleton* Singleton::getInstance()
{
    lock_guard<mutex> l(m_mutex);
	if (instance == nullptr)
	{
		cout << "实例为空，创建。" << endl;
		instance = new Singleton();
		cout << "地址" << instance << endl;
		cout << "创建结束" << endl;
	
	}
	else
	{
		cout << "实例存在，返回。" << endl;
	}
    return instance;
}

Singleton::Singleton()
{
	cout << "调用构造函数。" << endl;
}

Singleton::~Singleton()
{
	cout << "调用析构函数。" << endl;
}

Singleton::Delete::~Delete()
{
	if (instance != nullptr)
	{
		cout << "启动删除器。" << endl;
		delete instance;
		instance = nullptr;
	}
}
