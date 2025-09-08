#include "Singleton.h"
#include <thread>

shared_ptr<Singleton> Singleton::instance(new Singleton(), destoryInstance);

int main()
{
	cout << "主函数开始" << endl;
	thread t1([](){
			shared_ptr<Singleton> s1 = Singleton::getInstance();
	});

	thread t2([](){
			shared_ptr<Singleton> s2 = Singleton::getInstance();
	});
	t1.join();
	t2.join();
	cout << "主函数结束" << endl;
	return 0;
}