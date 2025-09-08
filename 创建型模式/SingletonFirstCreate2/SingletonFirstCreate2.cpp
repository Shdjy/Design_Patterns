#include "Singleton.h"
#include <thread>

Singleton* Singleton::instance = new Singleton();
Singleton::Delete Singleton::m_deleter;

int main()
{
	cout << "主函数开始" << endl;
	thread t1([]() {
		Singleton* s1 = Singleton::getInstance();
		});
	thread t2([]() {
		Singleton* s2 = Singleton::getInstance();
		});
	t1.join();
	t2.join();

	cout << "main结束" << endl;
	return 0;
}