#include "Singleton.h"

Singleton& Singleton::getInstance()
{
    cout << "��ȡʵ����" << endl;
    static Singleton instance;
    cout << "��ַ" << &instance << endl;
    return instance;
}

Singleton::Singleton()
{
    cout << "���ù��캯��" << endl;
}

Singleton::~Singleton()
{
    cout << "������������" << endl;
}
