#include <iostream>
#include <vector>

using namespace std;

class Observer 
{
public:
	virtual void Update(const string message) = 0;
	virtual ~Observer() {}
};

class Subject
{
public:
	void Attach(Observer* observer) {
		observers.push_back(observer);
	}

	void Detach(Observer* observer) {
		observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
	}

	void Notify(const string message) {
		for (auto observer : observers) {
			observer->Update(message);
		}
	}

private:
	vector<Observer*> observers;
};

class ConcreteObserver : public Observer 
{
public:
	void Update(const string message) override {
		cout << "Observer 1 received message: " << message << endl;
	}
};

class ConcreteObserver2 : public Observer 
{
public:
	void Update(const string message) override {
		cout << "Observer 2 received message: " << message << endl;
	}
};

int main() 
{
	Subject subject;
	ConcreteObserver observer1;
	ConcreteObserver2 observer2;

	subject.Attach(&observer1);
	subject.Attach(&observer2);

	subject.Notify("Hello World!");

	subject.Detach(&observer1);

	subject.Notify("Goodbye!");

	getchar();
	return 0;	
}