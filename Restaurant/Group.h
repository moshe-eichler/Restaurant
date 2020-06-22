#pragma once
#include "Table.h"

struct Group
{
	int m_nNumPeople;
	Table* m_SeatingTable;
	bool operator < (const Group& other) { return this->m_nNumPeople < other.m_nNumPeople; }
	Group() {};
	Group(int n, Table* t) : m_nNumPeople(n), m_SeatingTable(t) {};
};