#include "food1.h"
#include <iostream>
#include <fstream>

using namespace std;

Food1::Food1(std::string name_value, int quality_value, double price_value, class Date date_value, class Date sell_date_value)
{
	Common(name_value, quality_value, price_value, date_value);
	sell_date = class Date(sell_date_value);
	counter++;
}

Food1::Food1()
{
	Common();
	sell_date = Date();
	counter++;
}

Food1::~Food1()
{
	//std::cout << "Объект Food1 уничтожен." << std::endl;
	counter--;
}

Food1* Food1::Add_Food(Food1* food_mas)
{
	Food1* base_error = food_mas;
	int counter = food_mas[0].Get_Counter();
	Food1* base_cpy = new Food1[counter + 1];
	memcpy(base_cpy, food_mas, sizeof(Food1) * counter);


	std::string name_value;
	cout << "Введите название:" << endl;
	cin >> name_value;
	base_cpy[counter].Set_Name(name_value);

	cout << "Выберите кол-во продукта" << endl;
	int number_value;
	for (;;)
	{
		try
		{
			cin >> number_value;
			if (number_value < 0) throw - 1;
		}
		catch (...)
		{
			continue;
		}
		break;
	}
	base_cpy[counter].Set_Quantity(number_value);

	cout << "Выберите цену продукта" << endl;
	double price_value;
	for (;;)
	{
		try
		{
			cin >> price_value;
			if (price_value < 0) throw - 1;
		}
		catch (...)
		{
			continue;
		}
	    break;
	}
	base_cpy[counter].Set_Price(price_value);
	

	for (;;)
	{
		cout << "Выберите дату создания продукта через пробел" << endl;
		int a, b, c;
		cin >> a >> b >> c;
		if (a <= 0 || b <= 0 || c <= 0)
		{
			cout << "Невреная дата" << endl;
			continue;
		}
		if (b > 12)
		{
			cout << "Невреная дата" << endl;
			continue;
		}
		else
		{
			if (b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12)
			{
				if (c > 31) {
					cout << "Невреная дата" << endl;
					continue;
				}
			}
			else if (b == 4 || b == 6 || b == 9 || b == 11)
			{
				if (c > 30) {
					cout << "Невреная дата" << endl;
					continue;
				}
			}
			else if (b == 2)
			{
				if (a % 4 != 0)
				{
					if (c > 28) {
						cout << "Невреная дата" << endl;
						continue;
					}
				}
				else
				{
					if (c > 29)
					{
						cout << "Невреная дата" << endl;
						continue;
					}
				}
			}
		}
		base_cpy[counter].Set_Date(class Date(a, b, c));
		break;
	}

	for (;;)
	{
		cout << "Выберите дату продукта через пробел" << endl;
		int a, b, c;
		cin >> a >> b >> c;
		if (a <= 0 || b <= 0 || c <= 0)
		{
			cout << "Невреная дата" << endl;
			continue;
		}
		if (b > 12)
		{
			cout << "Невреная дата" << endl;
			continue;
		}
		else
		{
			if (b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12)
			{
				if (c > 31) {
					cout << "Невреная дата" << endl;
					continue;
				}
			}
			else if (b == 4 || b == 6 || b == 9 || b == 11)
			{
				if (c > 30) {
					cout << "Невреная дата" << endl;
					continue;
				}
			}
			else if (b == 2)
			{
				if (a % 4 != 0)
				{
					if (c > 28) {
						cout << "Невреная дата" << endl;
						continue;
					}
				}
				else
				{
					if (c > 29)
					{
						cout << "Невреная дата" << endl;
						continue;
					}
				}
			}
		}
		base_cpy[counter].Set_SellDate(class Date(a, b, c));
		break;
	}

	


	
	

	base_cpy->Counter1(counter + 1);
	return base_cpy;
}

Food1* Food1::Add1_Food(Food1* food_mas) // Новая функция ввода с клавиатуры (вместо Add_Food)
{
	Food1* base_error = food_mas;
	int counter = food_mas[0].Get_Counter();
	Food1* base_cpy = new Food1[counter + 1];
	memcpy(base_cpy, food_mas, sizeof(Food1) * counter);
	delete[] food_mas;

	std::cout << "Введите через пробел следующие данные:" << std::endl;
	std::cout << "Название Количество Цена Год Месяц День Год Месяц День." << std::endl;
	std::cin >> base_cpy[counter];

	return base_cpy;
}


void Food1::Print_Info(Food1* base)
{
	printf("Название      Кол-во    Цена   Дата создания Дата продажи\n");
	printf("-----------------------------------------------------------------------\n");
	for (int i = 0; i < base[0].Get_Counter(); i++)
	{
		cout << base[i] << endl;
	}
}

void Food1::Exit(Food1* base)
{
	ofstream file;
	file.open("food_base1.txt", ios_base::trunc);

	for (int i = 0; i < counter; i++)
	{
		file << base[i].Name() << endl;
		file << base[i].Number() << endl;
		file << base[i].Price() << endl;
		file << base[i].Create_Date().Year() << " " << base[i].Create_Date().Month() << " " << base[i].Create_Date().Day() << endl;
		file << base[i].Sell_Date().Year() << " " << base[i].Sell_Date().Month() << " " << base[i].Sell_Date().Day() << endl;
	}
}

void Food1::Name_Search(Food1* base)
{
	string tmp;
	cout << "Введите искомый товар." << endl;
	cin >> tmp;
	printf("Название      Кол-во    Цена   Дата создания Дата продажи\n");
	printf("-----------------------------------------------------------------------\n");
	for (int i = 0; i < base[0].counter; i++)
	{
		if (tmp == base[i].Name())
		{
			cout << base[i] << endl;
		}
	}
}

void Price_Sort(Food1* base)
{
	int counter = base[0].Get_Counter();
	for (int i = 0; i < counter - 1; i++)
	{
		for (int j = 0; j < counter - i - 1; j++)
		{
			if (base[j].Price() < base[j + 1].Price())
			{
				swap(base[j], base[j + 1]);
				base->Counter1();
			}
		}
	}
}



bool operator == (Food1& food1, Food1& food2)
{
	if (food1.Name() != food2.Name()) return false;
	if (food1.Get_Quantity() != food2.Get_Quantity()) return false;
	if (food1.Get_Price() != food2.Get_Price()) return false;
	if (food1.Create_Date().Date_To_String() != food2.Create_Date().Date_To_String()) return false;
	if (food1.Sell_Date().Date_To_String() != food2.Sell_Date().Date_To_String()) return false;

	return true;
}

std::ostream& operator <<(std::ostream& out, Food1& food) {

	out << food.Name() << ' '  << food.Get_Quantity() << "     " << food.Get_Price() << "     " << food.Create_Date().Date_To_String() << ' ' << food.Sell_Date().Date_To_String();
	return out;
}

Food1& Food1::operator= (Food1 food1)
{
	if (*this == food1) return *this;
	this->Set_Name(food1.Get_Name());
	this->Set_Quantity(food1.Get_Quantity());
	this->Set_Price(food1.Get_Price());
	this->Set_Date(food1.Get_Date());
	this->Set_SellDate(food1.Sell_Date());
	return *this;
}

std::istream& operator >>(std::istream& in, Food1& food1)
{
	std::string tmp;
	in >> tmp;
	food1.Set_Name(tmp);
	int tmp_quantity;
	try
	{
		in >> tmp_quantity;
		food1.Set_Quantity(tmp_quantity);
	}
	catch (...)
	{
		std::cout << "Ошибка ввода количества. Выставлено стандартное значение." << std::endl;
		food1.Set_Quantity(1);
	}
	double tmp_price;
	try
	{
		in >> tmp_price;
		food1.Set_Price(tmp_price);
	}
	catch (...)
	{
		std::cout << "Ошибка ввода цены. Выставлено стандартное значение." << std::endl;
		food1.Set_Price(100);
	}
	int a, b, c;
	try
	{
		in >> a >> b >> c;
		if (a <= 0 || b <= 0 || c <= 0)
		{
			cout << "Невреная дата" << endl;
			throw - 1;
		}
		if (b > 12)
		{
			cout << "Невреная дата" << endl;
			throw - 1;
		}
		else
		{
			if (b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12)
			{
				if (c > 31) {
					cout << "Невреная дата" << endl;
					throw - 1;
				}
			}
			else if (b == 4 || b == 6 || b == 9 || b == 11)
			{
				if (c > 30) {
					cout << "Невреная дата" << endl;
					throw - 1;
				}
			}
			else if (b == 2)
			{
				if (a % 4 != 0)
				{
					if (c > 28) {
						cout << "Невреная дата" << endl;
						throw - 1;
					}
				}
				else
				{
					if (c > 29)
					{
						cout << "Невреная дата" << endl;
						throw - 1;
					}
				}
			}
		}
		food1.Common::Set_Date(a, b, c);
	}
	catch (...)
	{

		food1.Common::Set_Date(2000, 1, 1);
	}
	try
	{
		in >> a >> b >> c;
		if (a <= 0 || b <= 0 || c <= 0)
		{
			cout << "Невреная дата" << endl;
			throw - 1;
		}
		if (b > 12)
		{
			cout << "Невреная дата" << endl;
			throw - 1;
		}
		else
		{
			if (b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12)
			{
				if (c > 31) {
					cout << "Невреная дата" << endl;
					throw - 1;
				}
			}
			else if (b == 4 || b == 6 || b == 9 || b == 11)
			{
				if (c > 30) {
					cout << "Невреная дата" << endl;
					throw - 1;
				}
			}
			else if (b == 2)
			{
				if (a % 4 != 0)
				{
					if (c > 28) {
						cout << "Невреная дата" << endl;
						throw - 1;
					}
				}
				else
				{
					if (c > 29)
					{
						cout << "Невреная дата" << endl;
						throw - 1;
					}
				}
			}
		}
		Date tmp_date = Date(a, b, c);
		food1.Set_SellDate(tmp_date);
	}
	catch (...)
	{

		Date tmp_date = Date(2000, 1, 1);
		food1.Set_SellDate(tmp_date);
	}
	return in;
}