#include "date.h"
#include <string>
#include <iostream>

using namespace std;

Date::Date(int year_value, int month_value, int day_value)
{
	if (year_value <= 0 || month_value <= 0 || day_value <= 0)
	{
		cout << "Невреная дата" << endl;

	}
	else { year = year_value; }
	if ( month_value > 12)
	{
		cout << "Невреная дата" << endl;
	}
	else
	{
		if (month_value == 1 || month_value == 3 || month_value == 5 || month_value == 7 || month_value == 8 || month_value == 10 || month_value == 12)
		{
			month = month_value;
			if (day_value > 31) cout << "Невреная дата" << endl;
			else day = day_value;
		}
		else if (month_value == 4 || month_value == 6 || month_value == 9 || month_value == 11)
		{
			month = month_value;
			if (day_value > 30) cout << "Невреная дата" << endl;
			else day = day_value;
		}
		else if (month_value == 2)
		{
			month = month_value;
			if (year_value % 4 != 0)
			{
				if (day_value > 28) cout << "Невреная дата" << endl;
				else day = day_value;
			}
			else
			{
				if (day_value > 29) throw new exception("Input error.\n");
				else day = day_value;
			}
		}
	}

	day = day_value;
}
Date::Date() : Date(2000, 1, 1)
{

}
Date::Date(const Date& date_value) : Date(date_value.year, date_value.month, date_value.day)
{

}

Date::~Date()
{
	
}

int Date::Year()
{
	return this->year;
}
int Date::Month()
{
	return this->month;
}
int Date::Day()
{
	return this->day;
}
string Date::Date_To_String()
{
	string str1 = to_string(this->Year());
	str1 += '.';
	str1 += to_string(this->Month());
	str1 += '.';
	str1 += to_string(this->Day());
	return str1;
}

bool operator == (Date date1, Date date2)
{
	if (date1.year != date2.year) return false;
	if (date1.month != date2.month) return false;
	if (date1.day != date2.day) return false;
	return true;
	//Альтернативный вариант
	//if (date1.Date_To_String() != date2.Date_To_String()) return false;
	//else return true;
}