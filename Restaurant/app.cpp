#pragma once
#include "Restaurant.h"

int main()
{
	Restaurant r("tfile.txt", "mfile.txt");
	r.AddToWaitList(1);
	r.AddToWaitList(50);
	r.AddToWaitList(40);
	r.AddToWaitList(1500);
	r.AddToWaitList(8);
	r.AddToWaitList(0);
	r.AddToWaitList(5);
	r.AddToWaitList(99);
	r.SitAtTable();
	r.SitAtTable();
	r.SitAtTable();
	string dish[3] = { "p", "f", "o" };
	int num_dish[3] = { 2, 1, 3 };
	r.GetOrder(3, dish, num_dish);
	string dish2[3] = { "p", "f", "s" };
	int num_dish2[3] = { 888, 1, 3 };
	r.GetOrder(3, dish2, num_dish2);
	r.GetCheck();
	r.SitAtTable();
	r.SitAtTable();
	r.SitAtTable();
	r.SitAtTable();
	r.SitAtTable();
	string dish1[3] = { "f", "o", "s" };
	int num_dish1[3] = { 2, 1, 3 };
	r.GetOrder(3, dish1, num_dish1);
	r.GetOrder(3, dish1, num_dish1);
	r.PrintCheckList();
	r.PrintServedList();
	r.PrintWaitList();
	r.PrintOpenOrders();
	r.PrintProfits();
	r.PrintTables();
	r.GetCheck();
	r.SitAtTable();
	r.PrintTables();
	r.PrintCheckList();
}

