#pragma once
#include "Queue.h"

template <class T>
class PQueue : public Queue<T>
{
public:
	void push(const T& data) { Queue<T>::Q.AddSortedDesc(data); }
};
