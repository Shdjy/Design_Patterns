#include <iostream>

using namespace std;

class State
{
public:
	virtual void handle() = 0;
};

class ConcreteStateA : public State
{
public:
	void handle()
	{
		cout << "ConcreteStateA::handle()" << endl;
	}
};

class ConcreteStateB : public State
{
public:
	void handle()
	{
		cout << "ConcreteStateB::handle()" << endl;
	}
};

class Context
{
private:
	State* state;

public:
	Context(State* s)
	{
		state = s;
	}
	void setState(State* s)
	{
		state = s;
	}

	void handle()
	{
		state->handle();
	}
};
int main()
{
	State* a = new ConcreteStateA();
	State* b = new ConcreteStateB();
	Context c(a);
	c.handle();
	c.setState(b);
	c.handle();

	delete a;
	delete b;

	getchar();
	return 0;
}
