#pragma once
#include "Common.h"

class Food1: public Common
{
private:
	Date sell_date;
	static int counter;
public:
	Food1(std::string name_value, int quality_value, double price_value, Date date_value, Date sell_date_value);
	Food1();
	~Food1();

	std::string Name() { return Get_Name(); }
	int Number() { return Get_Quantity(); }
	double Price() { return Get_Price(); }
	Date Create_Date() { return Get_Date(); }
	Date Sell_Date() { return sell_date; }
	int Get_Counter() { return counter; }

	void Set_Name(std::string tmp) { Common::Set_Name(tmp); }
	void Set_Number(int tmp) { Common::Set_Quantity(tmp); }
	void Set_Price(double tmp) { Common::Set_Price(tmp); }
	void Set_Date(class Date tmp) { Common::Set_Date(tmp.Year(), tmp.Month(), tmp.Day()); };
	void Set_SellDate(class Date tmp) { sell_date = Date(tmp); }
	void Counter1() { counter++; }
	void Counter1(int cnt) { counter = cnt; }

	Food1* Add_Food(Food1*);
	Food1* Add1_Food(Food1* food_mas);
	void Print_Info(Food1*);
	void Exit(Food1*);
	void Name_Search(Food1*);
	friend void Price_Sort(Food1*);

	friend bool operator ==(Food1&, Food1&);
	friend std::ostream& operator <<(std::ostream&, Food1&);
	Food1& operator = (Food1);
	friend std::istream& operator >>(std::istream&, Food1&);
};

