#pragma once
#include "date.h"
#include "food_type.cpp"
#include <string>
#include "Common.h"

class Food: public Common
{
private:
	Product food_type;
	double weight;
	static int counter;
public:
	Food(std::string name_value, int quality_value, double price_value, Date date_value, Product food_type_value, double weight_value);
	Food();
	//Food(Food&);
	~Food();
	
	std::string Name() { return Get_Name(); }
	int Food_Type() {
		if (food_type == Product_Bulochka) { return 1; }
		if (food_type == Product_Pirojok) { return 2; }
		return 3;
	}
	double Weight() { return weight; }
	int Number() { return Get_Quantity(); }
	double Price() { return Get_Price(); }
	Date Date() { return Get_Date(); }
	int Get_Counter() { return counter; }

	std::string Food_Type_ToString();


	void Set_Name(std::string tmp) { Common::Set_Name(tmp); }
	void Set_Food_Type(int tmp) { 
		if (tmp == 1) food_type = Product_Bulochka;
		else if (tmp == 2) food_type = Product_Pirojok;
		else if (tmp == 3) food_type = Product_Pirojnoe;
	}
	void Set_Weight(double tmp) { weight = tmp; }
	void Set_Number(int tmp) { Common::Set_Quantity(tmp); }
	void Set_Price(double tmp) { Common::Set_Price(tmp); }
	void Set_Date(class Date tmp) { Common::Set_Date(tmp.Year(), tmp.Month(), tmp.Day()); }
	void Counter() { counter ++ ; }
	void Counter(int cnt) { counter = cnt; }

	Food* Add_Food(Food*);
	Food* Add1_Food(Food*);
	void Print_Info(Food*);
	void Exit(Food*);
	void Name_Search(Food*);
	friend void Price_Sort(Food*);

	friend bool operator ==(Food&, Food&);
	friend std::ostream& operator <<(std::ostream&, Food&);
	Food& operator = ( Food);
	friend std::istream& operator >>(std::istream&, Food&);
};

