#include "Singleton.h"

Singleton* Singleton::getInstance()
{
    cout << "��ȡʵ��" << endl;
    cout << "��ַ" << instance << endl;
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

Singleton::Delete::Delete()
{
}

Singleton::Delete::~Delete()
{
    if (instance != nullptr)
    {
        cout << "����ɾ����" << endl;
        delete instance;
        instance = nullptr;
    }
}
