#pragma once
#include <string>
#include "date.h"

class Common
{
private:
	std::string name;
	int quantity;
	double price;
	Date create_date;
public:
	Common();
	Common(std::string name_value, int quality_value, double price_value, Date date_value);
	~Common();
	//Common(Common&);
	std::string Get_Name() { return name; }
	void Set_Name(std::string name_value) { name = name_value; };
	int Get_Quantity() { return quantity; }
	void Set_Quantity(int quantity_value) { quantity = quantity_value; }
	double Get_Price() { return price; }
	void Set_Price(double price_value) { price = price_value; }
	Date Get_Date() { return create_date; }
	void Set_Date(int, int, int);
};

