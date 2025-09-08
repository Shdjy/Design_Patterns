#include <iostream>
#include <memory>

using namespace std;

class PrintOut
{
public:
	virtual unique_ptr<PrintOut> clone() = 0;
	virtual void print() = 0;
};

class PrintString : public PrintOut
{
public:
	PrintString(string str) : m_str(str) {}
	void print()
	{
		cout << m_str << endl;
	}
	unique_ptr<PrintOut> clone()
	{
		return make_unique<PrintString>(*this);
	}

private:
	string m_str;
};

class PrintNumber : public PrintOut
{
public:
	PrintNumber(int num) : m_num(num) {}
	void print()
	{
		cout << m_num << endl;
	}

	unique_ptr<PrintOut> clone()
	{
		return make_unique<PrintNumber>(*this);
	}

private:
	int m_num;
};

int main()
{
	unique_ptr<PrintOut> p1 = make_unique<PrintString>("Hello, world!");
	unique_ptr<PrintNumber> p2 = make_unique<PrintNumber>(123);

	unique_ptr<PrintOut> p3 = p1->clone();
	p3->print();

	unique_ptr<PrintOut> p4 = p2->clone();
	p4->print();

	getchar();
	return 0;
}