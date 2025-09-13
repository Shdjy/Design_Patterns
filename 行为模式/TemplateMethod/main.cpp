#include <iostream>

using namespace std;

class AbstractClass
{
public:
	void templateMethod()
	{
		step1();
		step2();
		if (Hook())
		{
			step3();
		}
	}
	virtual void step1()
	{
		cout << "base step1" << endl;
	}
	virtual void step2() = 0;
	virtual void step3()
	{
		cout << "base step3" << endl;
	}

	virtual bool Hook()
	{
		return true;
	}
};

class ConcreteClassA : public AbstractClass
{
public:
	void step2()
	{
		cout << "step2 of ConcreteClassA" << endl;
	}
	bool Hook()
	{
		return false;
	}
};

class ConcreteClassB : public AbstractClass
{
public:
	void step2()
	{
		cout << "step2 of ConcreteClassB" << endl;
	}
	bool Hook()
	{
		return true;
	}
};

int main()
{
	ConcreteClassA a;
	a.templateMethod();

	ConcreteClassB b;
	b.templateMethod();

	getchar();
	return 0;
}