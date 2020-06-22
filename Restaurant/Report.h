/*
 *  Report.h
 *  hw4
 *
 *  Created by Masha Nikolski on 29/6/07 for @234122.
 *
 *  FUNCTIONALITY: 
 *		Includes definitions and printing purpose functions for hw4.
 * 
 *	FUNCTION LIST:
 * -----------------------------------------------------------------------------
 *	void ReportTable(ostream& s, 
 *					 const string& name, 
 *					 int cap, 
 *					 RSTableStatus st, 
 *					 int numPeople = 0);
 *
 *	Prints information about a table.
 *
 *  Parameters: 
 *		s - stream to print to.
 *      name - table name.
 *		cap - table maximum capacity.
 *		st - table status, one of the following TABLE_FREE, TABLE_WAIT_SERVICE, 
 *			or TABLE_WAIT_CHECK.
 *		numPeople - number of people occuping the table.
 *
 *  Return value:
 *		void
 *
 * -----------------------------------------------------------------------------
 *	void ReportWaitingList(ostream& s, const Queue<int>& line);
 *
 *	Prints information about a Queue of people outside the restaurant.
 *
 *  Parameters: 
 *		s - stream to print to.
 *      line - Queue of integers indicating sizes of groups waiting to enter 
 *			the restaurant.
 *
 *  Return value:
 *		void
 *
 *	Remarks:
 *		The Queue can be empty.
 * 
 * -----------------------------------------------------------------------------
 *	void ReportServedList(ostream& s, const Queue<string>& line);
 *
 *	Prints information about a Queue of tables waiting to be served (order to be
 *	taken).
 *
 *  Parameters: 
 *		s - stream to print to.
 *      line - Queue of strings indicating tables' names.
 *
 *  Return value:
 *		void
 *
 *	Remarks:
 *		The Queue can be empty.
 * 
 * -----------------------------------------------------------------------------
 *	void ReportCheckList(ostream& s, const Queue<string>& line);
 *
 *	Prints information about a Queue of tables waiting to get their check.
 *
 *  Parameters: 
 *		s - stream to print to.
 *      line - Queue of strings indicating tables' names.
 *
 *  Return value:
 *		void
 *
 *	Remarks:
 *		The Queue can be empty.
 * 
 * -----------------------------------------------------------------------------
 *	void ReportOrderList(ostream& s, const Queue<RestaurantOrder>& orders);
 *
 *	Prints information about a Queue of orders.
 *
 *  Parameters: 
 *		s - stream to print to.
 *      line - Queue of valid orders. If the orders are in non valid state
 *			(as defined in RestaurantOrder.h) function behaviour is undefined.
 *
 *  Return value:
 *		void
 *
 *	Remarks:
 *		The Queue can be empty.
 * 
 * -----------------------------------------------------------------------------
 *	void ReportProfit(ostream& s, const RestaurantOrder& order);
 *
 *	Prints information about profits.
 *
 *  Parameters: 
 *		s - stream to print to.
 *      order - valid RestaurantOrder object. If the object is in non valid state
 *			(as defined in RestaurantOrder.h) function behaviour is undefined.
 *
 *  Return value:
 *		void
 *
 *	Remarks:
 *		If there are no profits pass a RestaurantOrder parameter with 0 dishes.
 * 
 * -----------------------------------------------------------------------------
 *
 */


#pragma once
#include "RestaurantOrder.h"
#include "PQueue.h"
#include "Group.h"
#include <iostream>
#include <string>
using namespace std;

// Possible return values in Restaurant functions.
typedef enum{
	ILLEGAL_GROUP_SIZE = -1,
	NO_FREE_TABLE,
	NO_WAITING_GROUP,
	ILLEGAL_ORDER,
	SERVED_LIST_IS_EMPTY,
	CHECK_LIST_IS_EMPTY,
	BAD_PARAMETER,
	SUCCESS
} RSResult;

void ReportWaitingList(ostream& s, const Queue<int>& line);
void ReportServedList(ostream& s, const PQueue<Group>& line);
void ReportCheckList(ostream& s, const PQueue<Group>& line);
void ReportOrderList(ostream& s, const PQueue<RestaurantOrder>& orders);
void ReportProfit(ostream& s, const RestaurantOrder& order);