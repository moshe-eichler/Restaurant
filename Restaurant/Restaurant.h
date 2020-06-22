#pragma once

#include "Report.h"
#include "PQueue.h"
#include "Dish.h"
#include "RestaurantOrder.h"
#include <fstream>
using namespace std;


class Restaurant
{
	LinkedList<Table> m_RestaurantTables;
	LinkedList<string> m_RestaurantTablesName;
	LinkedList<Dish> m_RestaurantDishes;
	PQueue<RestaurantOrder> m_RestaurantOpenOrders;
	PQueue<RestaurantOrder> m_RestaurantOrders;
	Queue<int> m_Waiting_outside;
	PQueue<Group> m_Waiting_for_service;
	PQueue<Group> m_Waiting_for_a_check;
public:
	Restaurant(const char* tfile, const char* mfile);
	~Restaurant();
	RSResult AddToWaitList(int nGroupSize);
	RSResult SitAtTable();
	RSResult GetOrder(int nSize, const string* items, const int* itemsNum);
	RSResult GetCheck();
	void PrintWaitList() const;
	void PrintServedList() const;
	void PrintCheckList() const;
	void PrintOpenOrders() const;
	void PrintProfits() const;
	void PrintTables();
	Table* FindTable(const string& name);
	Dish* FindDish(const string& name);
};

