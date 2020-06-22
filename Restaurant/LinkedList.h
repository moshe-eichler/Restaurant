//#pragma once
//#include <iostream>
//
//
//template <class  T>
//struct Node
//{
//	T data;
//	Node<T>* next = NULL;
//	Node<T>* prev = NULL;
//	Node() {};
//	Node(const T& d) : data(d) {} ;
//};
//
//template <class  T>
//class LinkedList
//{
//	Node<T>* m_pHead;
//	Node<T>* m_pTail;
//	int m_nLength;
//public:
//	LinkedList();
//	~LinkedList();
//	void AddFirst(const T& data);
//	void AddLast(const T& data);
//	void AddSorted(const T& data);
//	void remove(const T& data);
//	void RemoveFirst();
//	void RemoveLast();
//	void print();
//	const T& GetFirst();
//	const T& GetLast();
//	int GetSize() { return this->m_nLength; }
//};
//
//template<class T>
//LinkedList<T>::LinkedList()
//{
//	this->m_pHead = NULL;
//	this->m_pTail = NULL;
//	this->m_nLength = 0;
//}
//
//template<class T>
//LinkedList<T>::~LinkedList()
//{
//
//}
//
//template<class T>
//void LinkedList<T>::AddFirst(const T& data)
//{
//	// Create new node
//	Node<T>* node = new Node<T>;
//	node->data = data;
//
//	// Add it to the beginning of the list
//	node->next = this->m_pHead;
//	this->m_pHead = node;
//
//	// If that's the only node we need the tail to point to it too
//	if (this->m_nLength == 0)
//		this->m_pTail = node;
//	// if not אז השני צריך להצביע עליו
//	else
//		node->next->prev = node;
//
//	this->m_nLength++;
//}
//
//template<class T>
//void LinkedList<T>::AddLast(const T& data)
//{
//	// Create new node
//	Node<T>* node = new Node<T>;
//	node->data = data;
//
//	// Add it at the end of the list, 
//	node->prev = this->m_pTail;
//	this->m_pTail = node;
//
//	// If that's the only node we need the head to point to it too
//	if (this->m_nLength == 0)
//		this->m_pHead = node;
//	// If not אז אחד לפני אחרון צריך להצביע עליו
//	else
//		node->prev->next = node;
//
//	this->m_nLength++;
//}
//
//template<class T>
//void LinkedList<T>::AddSorted(const T& data)
//{
//	// Create new node
//	Node<T>* node = new Node<T>;
//	node->data = data;
//
//	// If that's the only node
//	if (this->m_nLength == 0)
//	{
//		this->m_pHead = node;
//		this->m_pTail = node;
//
//		this->m_nLength++;
//
//		return;
//	}
//
//	// Try to add it in the first possible place from the end
//	Node<T>* to_add = this->m_pTail;
//	while (to_add && to_add->data < data)
//		to_add = to_add->prev;
//
//	// If it's the biggest
//	if (!to_add)
//	{
//		node->next = this->m_pHead;
//		this->m_pHead = node;
//	}
//	else
//	{
//		node->next = to_add->next;
//		to_add->next = node;
//
//		// If it's the smallest
//		if (to_add == this->m_pTail)
//			this->m_pTail = node;
//		else
//			node->next->prev = node;
//	}
//
//	node->prev = to_add;
//
//	this->m_nLength++;
//}
//
//template<class T>
//void LinkedList<T>::remove(const T& data)
//{
//	// If the list is empty
//	if (this->m_nLength == 0)
//		return;
//
//	// Remove head
//	if (this->m_pHead->data == data)
//	{
//		this->m_pHead = this->m_pHead->next;
//		delete this->m_pHead->prev;
//		this->m_pHead->prev = NULL;
//
//		this->m_nLength--;
//
//		return;
//	}
//
//	// Remove other
//	Node<T>* tmp = this->m_pHead;
//	while (tmp->next)
//	{
//		if (tmp->next->data == data)
//		{
//			Node<T>* to_delete = tmp->next;
//			tmp->next = tmp->next->next;
//
//			// Check if it's the latest node or not
//			if (tmp->next)
//				tmp->next->prev = tmp;
//			else
//				this->m_pTail = tmp;
//
//			delete to_delete;
//
//			this->m_nLength--;
//			
//			return;
//		}
//		tmp = tmp->next;
//	}
//}
//
//template<class T>
//void LinkedList<T>::RemoveFirst()
//{
//	if (this->m_nLength == 0)
//		return;
//
//	Node<T>* to_delete = this->m_pHead;
//	this->m_pHead = this->m_pHead->next;
//	delete to_delete;
//	if (this->m_pHead)
//		this->m_pHead->prev = NULL;
//
//	this->m_nLength--;
//}
//
//template<class T>
//void LinkedList<T>::RemoveLast()
//{
//	if (this->m_nLength == 0)
//		return;
//
//	Node<T>* to_delete = this->m_pTail;
//	this->m_pTail = this->m_pTail->prev;
//	delete to_delete;
//	if (this->m_pTail)
//		this->m_pTail->next = NULL;
//
//	this->m_nLength--;
//}
//
//template<class T>
//void LinkedList<T>::print()
//{
//	Node<T>* to_print = this->m_pHead;
//	while (to_print)
//	{
//		std::cout << to_print->data;
//		to_print = to_print->next;
//	}
//}
//
//template<class T>
//const T& LinkedList<T>::GetFirst()
//{
//	if (this->m_nLength == 0)
//		return NULL;
//
//	return this->m_pHead->data;
//}
//
//template<class T>
//const T& LinkedList<T>::GetLast()
//{
//	if (this->m_nLength == 0)
//		return NULL;
//
//	return this->m_pTail->data;
//}

#pragma once
#include "Iterator.h"

template <class  T>
class LinkedList
{
	Node<T>* m_pHead;
	Node<T>* m_pTail;
	int m_nLength;
public:
	LinkedList();
	~LinkedList();
	void AddLast(const T& data);
	void AddSortedAsc(const T& data);
	void AddSortedDesc(const T& data);
	const T& GetFirstData();
	const T& GetLastData();
	Node<T>* GetHead() const { return this->m_pHead; }
	//Node<T>* GetTail() const { return this->m_pTail; }
	//Node<T>* Find(const T& data);
	void RemoveFirst();
	void print();
	int GetSize() const { return this->m_nLength; }
};

template<class T>
LinkedList<T>::LinkedList()
{
	this->m_pHead = NULL;
	this->m_pTail = NULL;
	this->m_nLength = 0;
}

template<class T>
LinkedList<T>::~LinkedList()
{

}

template<class T>
void LinkedList<T>::AddLast(const T& data)
{
	// Create new node
	Node<T>* node = new Node<T>(data);

	// If that's the only node
	if (!this->m_pHead)
		this->m_pHead = node;
	else
		this->m_pTail->next = node;
	this->m_pTail = node;

	this->m_nLength++;
}

template<class T>
void LinkedList<T>::AddSortedAsc(const T& data)
{
	// If that's the only node
	if (!this->m_pHead)
		this->AddLast(data);

	else
	{
		// Create new node
		Node<T>* node = new Node<T>(data);

		// If it's the smallest
		if (data < this->m_pHead->data)
		{
			node->next = this->m_pHead;
			this->m_pHead = node;
		}
		else
		{
			// Find the place to add it
			Node<T>* to_add = this->m_pHead;
			while (to_add != this->m_pTail)
			{
				if (data < to_add->next->data)
					break;
				to_add = to_add->next;
			}

			if (to_add == this->m_pTail)
				this->m_pTail = node;
			node->next = to_add->next;
			to_add->next = node;
		}
		this->m_nLength++;
	}
}

template<class T>
void LinkedList<T>::AddSortedDesc(const T& data)
{
	// If that's the only node
	if (!this->m_pHead)
		this->AddLast(data);

	else
	{
		// Create new node
		Node<T>* node = new Node<T>(data);

		// If it's the biggest
		if (this->m_pHead->data < data)
		{
			node->next = this->m_pHead;
			this->m_pHead = node;
		}
		else
		{
			// Find the place to add it
			Node<T>* to_add = this->m_pHead;
			while (to_add != this->m_pTail)
			{
				if (to_add->next->data < data)
					break;
				to_add = to_add->next;
			}

			// If its the smallest we need to update the tail
			if (to_add == this->m_pTail)
				this->m_pTail = node;
			node->next = to_add->next;
			to_add->next = node;
		}
		this->m_nLength++;
	}
}

template<class T>
const T& LinkedList<T>::GetFirstData()
{
	if (this->m_pHead)
		return this->m_pHead->data;
}

template<class T>
const T& LinkedList<T>::GetLastData()
{
	if (this->m_pTail)
		return this->m_pTail->data;
}

template<class T>
void LinkedList<T>::RemoveFirst()
{
	if (!this->m_pHead)
		return;

	Node<T>* to_delete = this->m_pHead;
	if (this->m_pHead == this->m_pTail)
		this->m_pTail = NULL;
	this->m_pHead = this->m_pHead->next;
	delete to_delete;

	this->m_nLength--;
}

template<class T>
void LinkedList<T>::print()
{
	Node<T>* to_print = this->m_pHead;
	while (to_print)
	{
		std::cout << to_print->data;
		to_print = to_print->next;
	}
}