#include <iostream>
#include "Iterator.h"
#include "MyList.h"
#include <vector>

using namespace std;

int main()
{
	vector<int> vec = { 1, 2, 3, 4, 5 };
	vector<string> name = { "Alice","Bob","Charlie","David", "Eve" };

	MyList<int> list;
	MyList<string> nameList;
	for (size_t i = 0; i < vec.size(); i++)
	{
		list.push_back(vec.at(i));
		nameList.push_back(name.at(i));
	}
	ForwardIterator<int> forwardIt(list);
	cout << "Forward Iterator: " << endl;
	for (auto begin = forwardIt.First(); !forwardIt.IsDone(); begin = forwardIt.Next())
	{
		cout << begin->m_data << endl;
	}

	ReverseIterator<string> reverseIt(nameList);
	cout << "Reverse Iterator: " << endl;
	for (auto begin = reverseIt.First(); !reverseIt.IsDone(); begin = reverseIt.Next())
	{
		cout << begin->m_data << endl;
	}

	getchar();
	return 0;
}


