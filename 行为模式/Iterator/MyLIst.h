#pragma once


template<typename T>
class Node
{
public:
	T m_data;
	Node(T data) : m_data(data) {}
	Node* m_next = nullptr;
	Node* m_prev = nullptr;
};

template<typename T>
class MyList
{
public:
	inline int GetCount() const { return m_count; }
	inline bool IsEmpty() const { return m_count == 0; }
	inline Node<T>* GetHead() const { return m_head; }
	inline Node<T>* GetTail() const { return m_tail; }
	Node<T>* push_back(T data);
	Node<T>* push_front(T data);
	Node<T>* insert(Node<T>* node, T data);

private:
	Node<T>* m_head = nullptr;
	Node<T>* m_tail = nullptr;	
	int m_count = 0;
};

template<typename T>
Node<T>* MyList<T>::insert(Node<T>* item, T data)
{
	Node<T>* node = nullptr;
	if (node == m_head)
	{
		node = push_front(data);
	}
	else
	{
		node = new Node<T>(data);
		node->m_prev = item->m_prev;
		node->m_next = item;
		item->m_prev->m_next = node;
		item->m_prev = node;	
	}
	m_count++;
	return node;
}

template<typename T>
Node<T>* MyList<T>::push_front(T data)
{
	Node<T>* newNode = new Node<T>(data);
	if (m_head == nullptr)
	{
		m_head = m_tail = newNode;
	}
	else
	{
		newNode->m_next = m_head;
		m_head->m_prev = newNode;
		m_head = newNode;
	}
	m_count++;
	return newNode;	
}

template<typename T>
Node<T>* MyList<T>::push_back(T data)
{
	Node<T>* newNode = new Node<T>(data);
	if (m_tail == nullptr)
	{
		m_head = m_tail = newNode;
	}
	else
	{
		newNode->m_prev = m_tail;
		m_tail->m_next = newNode;
		m_tail = newNode;
	}
	m_count++;
	return newNode;
}

