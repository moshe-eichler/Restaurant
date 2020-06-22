/*
 *  OrderItem.h
 *  hw4
 *
 *  Created by Masha Nikolski on 11/7/07 for @234122.
 *
 *  FUNCTIONALITY: 
 *		Implements one entry in a restaurant order.
 *		An entry includes dish name, dish price and ammount of such dishes.
 *	
 *	MEMBERS:
 * -----------------------------------------------------------------------------
 *	OrderItem(const string& name = "", 
 *			  const double& price = 0.0, 
 *			  const int& ammount = 0);
 *
 *	Constructor
 *
 *  Parameters: 
 *		name - Dish name, can be "".
 *		price - Dish price, with a default value of 0.0.
 *		ammount - Number of such dishes in an order.
 *
 *	Remarks:
 *		Assumes that price and ammount are non negative.
 *		No error is given in case of wrong parameters.
 *
 * -----------------------------------------------------------------------------
 *	virtual ~OrderItem();
 *
 *	Destructor
 *
 * -----------------------------------------------------------------------------
 *	const  string Name() const;
 *
 *	Returns dish name.
 *
 *  Parameters: 
 *		none
 *
 *  Return value:
 *		const  string - dish name.
 *
 * -----------------------------------------------------------------------------
 *  double PricePerItem() const;
 *
 *	Returns dish price.
 *
 *  Parameters: 
 *		none
 *
 *  Return value:
 *		double - dish price.
 *
 * -----------------------------------------------------------------------------
 *  double TotalPrice() const;
 * 
 *	Returns the total price of a dish in an order, according to the number of 
 *	such ordered dishes.
 *
 *  Parameters: 
 *		none
 *
 *  Return value:
 *		double - total price for a dish.
 *
 * -----------------------------------------------------------------------------
 * int Ammount() const;
 *
 *	Returns how much times the dish appeared in the order. 
 *
 *  Parameters: 
 *		none
 *
 *  Return value:
 *		int - number of such oredered dishes.
 * 
 * -----------------------------------------------------------------------------
 *  OrderItem operator+(const int& i) const;
 *
 *	Increments the ammount of such ordered dishes.  
 *
 *  Parameters: 
 *		i - number of dishes to be added, must be non negative.
 *          In case of an illegal value, the outcome of the function is undefined.
 *
 *  Return value:
 *		OrderItem - a new item with incremented ammount.
 * 
 * -----------------------------------------------------------------------------
 *  OrderItem& operator+=(const int& o);
 *
 *	Increments the ammount of such ordered dishes.  
 *  Parameters: 
 *		i - number of dishes to be added, must be non negative.
 *          In case of an illegal value, the outcome of the function is undefined.
 *
 *  Return value:
 *		OrderItem& - a reference to an updated OrderItem.
 *
 * -----------------------------------------------------------------------------
 *  bool operator<(const OrderItem& o) const;
 *
 *	Defines an order of precedence between two OrderItems. 
 *
 *  Parameters: 
 *		o - OrderItem to compare with.
 *
 *  Return value:
 *		bool - true if *this is lesser than o, false - otherwise.
 * 
 * -----------------------------------------------------------------------------
 *  ostream& Print(ostream& s) const;
 *
 *	Prints the order to a stream. 
 *
 *  Parameters: 
 *		s - stream to print the order to.
 *
 *  Return value:
 *		ostream& - reference to the changed stream.
 * 
 * -----------------------------------------------------------------------------
 *
 * GLOBAL OPERATORS:
 * -----------------------------------------------------------------------------
 *  ostream& operator<<(ostream& s, const OrderItem& o);
 *
 *	Prints the order to a stream. 
 *
 *  Parameters: 
 *		s - stream to print the order to.
 *		o - order to print.
 *
 *  Return value:
 *		ostream& - reference to the changed stream.
 *
 * -----------------------------------------------------------------------------
 *  OrderItem operator+(const int& i, const OrderItem& o);
 *
 *	Increments the ammount of ordered dishes.   
 *
 *  Parameters: 
 *		i - number of dishes to be added, must be non negative.
 *          In case of an illegal value, the outcome of the function is undefined.
 *		o - an order.
 *
 *  Return value:
 *		OrderItem - a new item with incremented ammount.
 *
 * -----------------------------------------------------------------------------
*/
#pragma once
#ifndef ORDER_ITEM_H
#define ORDER_ITEM_H

#include <queue>
#include <vector>
#include <iostream>
#include <string>


using std::string;
using std::ostream;

class OrderItem 
{
	string m_sName;
	double m_dPrice;
	int    m_nAmmount;

public:
	OrderItem(const string& name = "",
			  const double& price = 0.0, 
			  const int& ammount = 0) :
		m_sName(name), m_dPrice(price), m_nAmmount(ammount)
	{}
	
	virtual ~OrderItem() {}
	
	const  string Name()  const { return m_sName; }
	double PricePerItem() const { return m_dPrice; }
	double TotalPrice()   const { return m_dPrice * m_nAmmount; }
	int    Ammount()      const { return m_nAmmount; }
	
	OrderItem operator+(const int& i) const;
	OrderItem& operator+=(const int& o);
	bool operator<(const OrderItem& o) const;

	// friend ostream& operator<<(ostream& s, const OrderItem& o);
};
// ostream& operator<<(ostream& s, const OrderItem& o);

#endif // ORDER_ITEM_H
