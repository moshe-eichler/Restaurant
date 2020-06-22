#pragma once
#include <string>
using namespace std;

struct Dish
{
	string name;
	double price;
public:
	Dish(const string& name, const double& price) : name(name), price(price) {};
	~Dish() {};
};

