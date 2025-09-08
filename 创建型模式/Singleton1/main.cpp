#include "Singleton.h"
#include <thread>

//��ʼ��
shared_ptr<Singleton> Singleton::instance = nullptr;
mutex Singleton::m_mutex;

int main()
{
	cout << "��������ʼ:" << endl;
	//Singleton* s1 = Singleton::getInstance();
	//Singleton* s2 = Singleton::getInstance();
	thread t1([]() {
		shared_ptr<Singleton> s1 = Singleton::getInstance();
		});
	thread t2([]() {
		shared_ptr<Singleton> s2 = Singleton::getInstance();
		});
	t1.join();
	t2.join();
	shared_ptr<Singleton> s3 = Singleton::getInstance();
	cout << "��ַ��" << s3 << endl;
	cout << "������������" << endl;
	return 0;
}


/*��������ʼ:
ʵ��Ϊ�գ�������
���ù��캯��.
��ַ��00000258CBD85FE0
��������
����ʵ�������أ�
����ʵ�������أ�
��ַ��00000258CBD85FE0
������������*/
//����������Ļ������߳��л��������new�������������ֻ�ܲ�׽��һ��new�ĵ�ַ��Ϣ��ǰ��Ķ�ʧ�ˡ�