#include "Singleton.h"

shared_ptr<Singleton> Singleton::getInstance()
{
    cout << "获取实例" << endl;
    cout << "地址" << instance << endl;

    return instance;
}

void Singleton::destoryInstance(Singleton* x)
{
    cout << "自定义释放实例" << endl;
    delete x;
}

Singleton::Singleton()
{
    cout << "调用构造函数" << endl;
}

Singleton::~Singleton()
{
    cout << "调用析构函数" << endl;
}
