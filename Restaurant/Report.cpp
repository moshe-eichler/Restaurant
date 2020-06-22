/*
 *  Report.cpp
 *  hw4
 *
 *  Created by Masha Nikolski on 29/6/07.
 *
 */
#pragma once
#include "Report.h"
#include <iostream>
#include <string>
using namespace std;

static string ToString(RSTableStatus s);

ostream& operator <<(ostream& os, const Queue<int>& pq)
{
	Queue<int> temp(pq);

	while (!temp.empty())
	{
		os << temp.front() << endl;
		temp.pop();
	}
	return os;
}

ostream& operator <<(ostream& os, const PQueue<Group>& pq)
{
	PQueue<Group> temp(pq);

	while (!temp.empty())
	{
		os << temp.front().m_SeatingTable->m_Name << endl;
		temp.pop();
	}
	return os;
}

ostream& operator <<(ostream& os, const PQueue<RestaurantOrder>& pq)
{
	PQueue<RestaurantOrder> temp(pq);
	
	while (!temp.empty())
	{
		RestaurantOrder ro = temp.front();
		for (int i = 0; i < ro.NumDishes(); i++)
		{
			os << "Dish name: " << ro.Dishes()[i].Name() << endl;
			os << "Prisc: " << ro.Dishes()[i].PricePerItem() << endl;
			os << "Ammount: " << ro.Dishes()[i].Ammount() << endl;
			os << "Total price: " << ro.Dishes()[i].TotalPrice() << endl << endl;
		}
		// os << endl;
		temp.pop();
	}
	return os;
}

ostream& operator <<(ostream& os, const RestaurantOrder& pq)
{
	for (int i = 0; i < pq.m_NumDishes; i++)
	{
		os << "Dish name: " << pq.m_Dishes[i].Name() << endl;
		os << "Prisc: " << pq.m_Dishes[i].PricePerItem() << endl;
		os << "Ammount: " << pq.m_Dishes[i].Ammount() << endl;
		os << "Total price: " << pq.m_Dishes[i].TotalPrice() << endl;
	}
	return os;
}

string ToString(RSTableStatus s)
{
	switch (s) {
		case TABLE_FREE:
			return "free";
		case TABLE_WAIT_SERVICE:
			return "waiting to be served";
		case TABLE_WAIT_CHECK:
			return "waiting for a check";
		default:
			return "TABLE_STATUS_ERROR";
	}
}

void ReportWaitingList(ostream& s, const Queue<int>& line)
{	
	if (line.empty())
		s << "There is no one waiting to enter the restaurant." << endl;
	else {
		s << "List of groups waiting for a table:" << endl;
		s << line << endl;
	}
}

void ReportServedList(ostream& s, const PQueue<Group>& line)
{
	if (line.empty())
		s << "There is no one waiting for service." << endl;
	else {
		s << "List of tables waiting for service:" << endl;
		s << line << endl;
	}
}

void ReportCheckList(ostream& s, const PQueue<Group>& line)
{
	if (line.empty())
		s << "There is no table waiting for a check." << endl;
	else {
		s << "List of tables waiting for a check:" << endl;
		s << line << endl;
	}
}

void ReportOrderList(ostream& s, const PQueue<RestaurantOrder>& orders)
{
	if (orders.empty())
		s << "There are no opened orders." << endl;
	else {
		s << "List of opened orders" << endl << endl;
		s << orders << endl;
	}
}


void ReportProfit(ostream& s, const RestaurantOrder& order)
{
	s << order << endl;
}
