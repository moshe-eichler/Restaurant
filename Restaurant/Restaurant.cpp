#include "Restaurant.h"

Restaurant::Restaurant(const char* tfile, const char* mfile) 
{
	// Add the tables to the restaurant
	ifstream table_file(tfile);
	string s_NumTables;
	table_file >> s_NumTables;
	int m_nNumTables = stoi(s_NumTables);

	for (int i = 0; i < m_nNumTables; i++)
	{
		string s_TableName, s_TableCapacity;
		table_file >> s_TableName;
		table_file >> s_TableCapacity;
		int n_Table_capacity = stoi(s_TableCapacity);

		// create and add the table to the restaurant
		Table table(s_TableName, n_Table_capacity);
		this->m_RestaurantTables.AddSortedAsc(table);
		this->m_RestaurantTablesName.AddSortedAsc(s_TableName);
	}

	// add the dishes to the restaurant
	ifstream dishes_file(mfile);

	// Because there are always 6 categories
	for (int i = 0; i < 6; i++)
	{
		string s_category, s_NumDishes;
		int n_NumDishes;
		dishes_file >> s_category;
		dishes_file >> s_NumDishes;
		n_NumDishes = stoi(s_NumDishes);

		for (int i = 0; i < n_NumDishes; i++)
		{
			string s_dish_name, s_dish_price;
			double d_dish_price;
			dishes_file >> s_dish_name;
			dishes_file >> s_dish_price;
			d_dish_price = stod(s_dish_price);

			// create and add the dish to the restaurant
			Dish dish(s_dish_name, d_dish_price);
			this->m_RestaurantDishes.AddLast(dish);
		}
	}
}

Restaurant::~Restaurant()
{

}

RSResult Restaurant::AddToWaitList(int nGroupSize)
{
	// If the group size is zero or negative number or bigger than the capacity of the biggest table
	if (nGroupSize < 1 || nGroupSize > this->m_RestaurantTables.GetLastData().m_nCapacity)
		return ILLEGAL_GROUP_SIZE;
	
	this->m_Waiting_outside.push(nGroupSize);
	return SUCCESS;
}

RSResult Restaurant::SitAtTable()
{
	if (this->m_Waiting_outside.empty())
		return NO_WAITING_GROUP;

	int group_size = this->m_Waiting_outside.front();
	Iterator<Table> it(this->m_RestaurantTables);
	while (it.HasNext())
	{
		Table& to_sit = it.Next();
		if (to_sit.Seat(group_size))
		{
			Group group(group_size, &to_sit);
			this->m_Waiting_for_service.push(group);
			this->m_Waiting_outside.pop();
			return SUCCESS;
		}
	}
	return NO_FREE_TABLE;
}

RSResult Restaurant::GetOrder(int nSize, const string* items, const int* itemsNum)
{
	// If one of the pointers is NULL
	if (!items || !itemsNum)
		return BAD_PARAMETER;

	if (nSize < 1)
		return ILLEGAL_ORDER;

	// Build an array of order item's
	OrderItem* array_of_order_items = new OrderItem[nSize];
	for (int i = 0; i < nSize; i++)
	{
		// Least one dish was ordered
		if (itemsNum[i] < 1)
			return ILLEGAL_ORDER;
		
		Dish* find_dish = FindDish(items[i]);
		// The dish not exist in the restaurant
		if (!find_dish)
			return ILLEGAL_ORDER;

		OrderItem order_item(items[i], find_dish->price, itemsNum[i]);
		array_of_order_items[i] = order_item;
	}

	// There is no one waiting for service
	if (this->m_Waiting_for_service.empty())
		return SERVED_LIST_IS_EMPTY;

	// Move the group from the queue waiting for service to the group waiting for a check
	Group group = this->m_Waiting_for_service.front();
	group.m_SeatingTable->GetOrder();
	this->m_Waiting_for_a_check.push(group);
	this->m_Waiting_for_service.pop();

	// Add the order to the order list's
	RestaurantOrder restaurant_order(group.m_nNumPeople, group.m_SeatingTable->m_Name, array_of_order_items, nSize);
	this->m_RestaurantOpenOrders.push(restaurant_order);
	this->m_RestaurantOrders.push(restaurant_order);

	return SUCCESS;
}

RSResult Restaurant::GetCheck()
{
	if (this->m_Waiting_for_a_check.empty())
		return CHECK_LIST_IS_EMPTY;

	this->m_Waiting_for_a_check.front().m_SeatingTable->GetUp();
	
	this->m_Waiting_for_a_check.pop();
	this->m_RestaurantOpenOrders.pop();
	
	return SUCCESS;
}

void Restaurant::PrintWaitList() const
{
	ReportWaitingList(cout, this->m_Waiting_outside);
}

void Restaurant::PrintServedList() const
{
	ReportServedList(cout, this->m_Waiting_for_service);
}

void Restaurant::PrintCheckList() const
{
	ReportCheckList(cout, this->m_Waiting_for_a_check);
}

void Restaurant::PrintOpenOrders() const
{
	ReportOrderList(cout, this->m_RestaurantOpenOrders);
}

void Restaurant::PrintProfits() const
{
	cout << "the profits of the restaurant are:" << endl << endl;
	PQueue<RestaurantOrder> ro(this->m_RestaurantOrders);
	while (!ro.empty())
	{
		ReportProfit(cout, ro.front());
		ro.pop();
	}
}

void Restaurant::PrintTables()
{	
	cout << endl << "Restaurant tables sorted by capacity" << endl;
	Iterator<Table> it_table(this->m_RestaurantTables);
	while (it_table.HasNext())
		it_table.Next().print(cout);

	cout << endl << "Restaurant tables sorted by name" << endl;
	Iterator<string> it_name(this->m_RestaurantTablesName);
	while (it_name.HasNext())
	{
		Table* table = FindTable(it_name.Next());
		table->print(cout);
	}
}

Table* Restaurant::FindTable(const string& name)
{
	if (this->m_RestaurantTables.GetSize())
	{
		Iterator<Table> it(this->m_RestaurantTables);
		while (it.HasNext())
		{
			Table& t = it.Next();
			if (t.m_Name == name)
				return &t;
		}
	}
	return NULL;
}

Dish* Restaurant::FindDish(const string& name)
{
	if (this->m_RestaurantDishes.GetSize())
	{
		Iterator<Dish> it(this->m_RestaurantDishes);
		while (it.HasNext())
		{
			Dish& d = it.Next();
			if (d.name == name)
				return &d;
		}
	}
	return NULL;
}

