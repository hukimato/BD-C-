#pragma once
#include <string>
class Date
{
private:
	int year;
	int month;
	int day;
public:
	Date(int, int, int);
	Date();
	Date(const Date&);
	~Date();
	int Year();
	int Month();
	int Day();
	std::string Date_To_String();
	friend bool operator ==(Date, Date);
};