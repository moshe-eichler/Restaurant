#pragma once
#include "Table.h"

bool operator<(const Table& left, const Table& right)
{
	if (left.m_nCapacity == right.m_nCapacity)
		return left.m_Name < right.m_Name;
	else
		return left.m_nCapacity < right.m_nCapacity;
}

bool Table::Seat(int n)
{
	if (this->m_nCapacity < n || this->m_Status != TABLE_FREE)
		return false;
	this->m_Status = TABLE_WAIT_SERVICE;
	this->m_nNumPeople = n;
	return true;
}

void Table::GetUp()
{
	this->m_nNumPeople = 0;
	this->m_Status = TABLE_FREE;
}

void Table::GetOrder()
{
	this->m_Status = TABLE_WAIT_CHECK;
}

string Table::ToString(RSTableStatus s)
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

void Table::print(ostream& s)
{
	if (this->m_Status == TABLE_FREE)
		s << "Table " << this->m_Name << ": "
		<< "capacity = " << this->m_nCapacity << ", status = " << ToString(this->m_Status) << "." << endl;
	else
		s << "Table " << this->m_Name << ": "
		<< "capacity = " << this->m_nCapacity << ", occupied by " << this->m_nNumPeople << ", status = " << ToString(this->m_Status) << "." << endl;
}
