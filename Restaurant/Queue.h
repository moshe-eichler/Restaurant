#pragma once
#include "LinkedList.h"
using namespace std;

template <class T>
class Queue
{
protected:
	LinkedList<T> Q;
public:
	Queue() {};
	Queue(const Queue& q);
	~Queue() {};
	void push(const T& data);
	void pop();
	const T& front();
	const T& back();
	bool empty() const;
	int size();
	//ostream& operator<<(ostream& os, Queue<T> to_print);
};

template<class T>
Queue<T>::Queue(const Queue& q)
{
	Iterator<T> it(q.Q);
	while (it.HasNext())
		this->Q.AddLast(it.Next());
}

template<class T>
void Queue<T>::push(const T& data)
{
	Q.AddLast(data);
}

template<class T>
void Queue<T>::pop()
{
	Q.RemoveFirst();
}

template<class T>
const T& Queue<T>::front()
{
	return Q.GetFirstData();
}

template<class T>
const T& Queue<T>::back()
{
	return Q.GetLastData();
}

template<class T>
bool Queue<T>::empty() const
{
	if (!Q.GetSize())
		return true;
	return false;
}

template<class T>
int Queue<T>::size()
{
	return Q.GetSize();
}

//template<class T>
//ostream& Queue<T>::operator<<(ostream& os, Queue<T> to_print)
//{
//	// TODO: insert return statement here
//}
