#include "Singleton.h"

Singleton& Singleton::getInstance()
{
    cout << "获取实例。" << endl;
    static Singleton instance;
    cout << "地址" << &instance << endl;
    return instance;
}

Singleton::Singleton()
{
    cout << "调用构造函数" << endl;
}

Singleton::~Singleton()
{
    cout << "调用析构函数" << endl;
}
