#include "Singleton.h"


Singleton* Singleton::getInstance()
{
    lock_guard<mutex> l(m_mutex);
	if (instance == nullptr)
	{
		cout << "ʵ��Ϊ�գ�������" << endl;
		instance = new Singleton();
		cout << "��ַ" << instance << endl;
		cout << "��������" << endl;
	
	}
	else
	{
		cout << "ʵ�����ڣ����ء�" << endl;
	}
    return instance;
}

Singleton::Singleton()
{
	cout << "���ù��캯����" << endl;
}

Singleton::~Singleton()
{
	cout << "��������������" << endl;
}

Singleton::Delete::~Delete()
{
	if (instance != nullptr)
	{
		cout << "����ɾ������" << endl;
		delete instance;
		instance = nullptr;
	}
}
