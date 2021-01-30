#include "Common.h"

Common::Common()
{
	name = "Standart Name";
	quantity = 0;
	price = 0;
	create_date = Date();
}

Common::Common(std::string name_value, int quality_value, double price_value, Date date_value)
{
	name = name_value;
	quantity = quality_value;
	create_date = Date(date_value);
}

Common::~Common()
{

}

//Common::Common(Common&)

void Common::Set_Date(int year, int month, int day)
{
	create_date = Date(year, month, day);
}