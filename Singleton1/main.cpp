#include "Singleton.h"
#include <thread>

//初始化
shared_ptr<Singleton> Singleton::instance = nullptr;
mutex Singleton::m_mutex;

int main()
{
	cout << "主函数开始:" << endl;
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
	cout << "地址是" << s3 << endl;
	cout << "主函数结束。" << endl;
	return 0;
}


/*主函数开始:
实例为空，创建！
调用构造函数.
地址是00000258CBD85FE0
创建结束
已有实例，返回！
已有实例，返回！
地址是00000258CBD85FE0
主函数结束。*/
//如果不加锁的话两个线程中会进行两次new操作，但是最后只能捕捉到一次new的地址信息，前面的丢失了。