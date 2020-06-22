#pragma once
#include <iostream>

template <class T>
class LinkedList;

template <class  T>
struct Node
{
	T data;
	Node<T>* next;
	Node(const T& d) : data(d), next(NULL) {};
	~Node() {};
};

template <class T>
class Iterator
{
	Node<T>* m_pNode;
public:
	Iterator(const LinkedList<T>& list);
	~Iterator() {};
	bool HasNext();
	T& Next();
};

template<class T>
Iterator<T>::Iterator(const LinkedList<T>& list)
{
	this->m_pNode = list.GetHead();
}

template <class T>
bool Iterator<T>::HasNext()
{
	return (this->m_pNode) ? true : false;
}

template<class T>
T& Iterator<T>::Next()
{
	if (this->m_pNode)
	{
		T& data = this->m_pNode->data;
		this->m_pNode = this->m_pNode->next;
		return data;
	}
}
