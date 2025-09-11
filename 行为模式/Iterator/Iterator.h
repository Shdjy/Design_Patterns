#pragma once
template<typename T>
class Node;
template<typename T>
class MyList;

template<typename T>
class MyIterator
{
public:
    virtual ~MyIterator() = default;
    MyIterator(MyList<T>& list) :m_list(list) {}
    Node<T>* Current()
    {
        return m_current;
    }
    virtual Node<T>* First() = 0;
    virtual Node<T>* Next() = 0;
    virtual bool IsDone() = 0;

protected:
    MyList<T>& m_list;
    Node<T>* m_current = nullptr;
};

template<typename T>
class ReverseIterator : public MyIterator<T>
{
public:
    using MyIterator<T>::MyIterator;
	using MyIterator<T>::m_current;   
    using MyIterator<T>::m_list;
    Node<T>* First() override
    {
        m_current = m_list.GetTail();
        return m_current;
    }
    Node<T>* Next() override
    {
        m_current = m_current->m_prev;
        return m_current;
    }
    bool IsDone() override
    {
        return m_current == m_list.GetHead()->m_prev;
    }
};
      
template<typename T>
class ForwardIterator : public MyIterator<T>
{
public:
    using MyIterator<T>::MyIterator;
	using MyIterator<T>::m_current;    
	using MyIterator<T>::m_list;
    Node<T>* First() override
    {
        m_current = m_list.GetHead();
        return m_current;
    }
    Node<T>* Next() override
    {
        m_current = m_current->m_next;
        return m_current;
    }
    bool IsDone() override
    {
        return m_current == m_list.GetTail()->m_next;
    }
};
