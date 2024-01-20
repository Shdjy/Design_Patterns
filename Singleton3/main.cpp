#include "Singleton.h"
#include <thread>

int main()
{
	cout << "主函数开始" << endl;
	thread t1([]() {
		Singleton& s1 = Singleton::getInstance();
		});

	thread t2([]() {
		Singleton& s2 = Singleton::getInstance();
		});
	t1.join();
	t2.join();

	cout << "主函数结束" << endl;
	return 0;
}