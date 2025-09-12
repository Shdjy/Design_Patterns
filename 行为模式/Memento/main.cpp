#include <iostream>
#include <vector>
using namespace std;

class Memento 
{
private:
	string m_state;
public:
	Memento(string state) : m_state(state) {}
	string get_state() { return m_state; }
};

class Originator 
{
private:
	string m_state;
public:
	void set_state(string state) { m_state = state; }
	string get_state() { return m_state; }
	Memento create_memento() { return Memento(m_state); }
	void restore_memento(Memento memento) { m_state = memento.get_state(); }
};

class Caretaker 
{
private:
	vector<Memento> m_mementos;
public:
	void add_memento(Memento memento) { m_mementos.push_back(memento); }
	Memento get_memento(int index) { return m_mementos[index]; }
};

int main() 
{
	Originator originator;
	originator.set_state("state1");
	Caretaker caretaker;
	caretaker.add_memento(originator.create_memento());
	originator.set_state("state2");
	caretaker.add_memento(originator.create_memento());
	originator.set_state("state3");
	caretaker.add_memento(originator.create_memento());

	originator.restore_memento(caretaker.get_memento(0));


	cout << "Current state:	" << originator.get_state() << endl;
	getchar();
	return 0;
}
