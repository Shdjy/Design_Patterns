#include "Singleton.h"

shared_ptr<Singleton> Singleton::getInstance()
{
    cout << "��ȡʵ��" << endl;
    cout << "��ַ" << instance << endl;

    return instance;
}

void Singleton::destoryInstance(Singleton* x)
{
    cout << "�Զ����ͷ�ʵ��" << endl;
    delete x;
}

Singleton::Singleton()
{
    cout << "���ù��캯��" << endl;
}

Singleton::~Singleton()
{
    cout << "������������" << endl;
}
