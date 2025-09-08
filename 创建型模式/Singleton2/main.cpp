#include "Singleton.h"
#include <thread>
#include <Windows.h>


Singleton* Singleton::instance = nullptr;
mutex Singleton::m_mutex;
Singleton::Delete Singleton::m_deleter;

int main()
{
	cout << "主函数开始。" << endl;
	thread t1([]() {
		Singleton* s1 = Singleton::getInstance();
		});
	thread t2([]() {
		Singleton* s2 = Singleton::getInstance();

		});
	t1.join();
	t2.join();
	
	Singleton* s3 = Singleton::getInstance();
	cout << "地址" << s3 << endl;
	cout << "结束" << endl;
	return 0; 
}