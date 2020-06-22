#pragma once
#include <string>
#include <iostream>
//#include "Report.h"
using namespace std;

// Possible status for a table in a restaurant.
typedef enum {
	TABLE_FREE,
	TABLE_WAIT_SERVICE,
	TABLE_WAIT_CHECK
} RSTableStatus;

struct Table
{
	string m_Name;
	int m_nCapacity;
	int m_nNumPeople;
	RSTableStatus m_Status;
	Table(const string& name, const int& capacity) : m_Name(name), m_nCapacity(capacity), m_Status(TABLE_FREE), m_nNumPeople(0) {};
	bool Seat(int n);
	void GetUp();
	void GetOrder();
	string ToString(RSTableStatus s);
	void print(ostream& s);
	// look here why i make it a friend function https://stackoverflow.com/questions/19709048/c-overloading-operator-for-struct-error-too-many-parameters
	friend bool operator < (const Table& left, const Table& right);
};
