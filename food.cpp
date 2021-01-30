#include "food.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Food::Food(std::string name_value, int quality_value, double price_value, class Date date_value, Product food_type_value, double weight_value)
{
	Common(name_value, quality_value, price_value, date_value);
	food_type = food_type_value;
	weight = weight_value;
	counter++;
}

Food::Food()
{
	Common();
	Set_Food_Type(1);
	weight = 0;
	counter++;
}

Food::Food(Food& food):
food_type(food.food_type), weight(food.weight)
{
	
	Common(food.Get_Name(), food.Get_Quantity(), food.Get_Price(), food.Get_Date());
	counter++;
}

Food::~Food()
{
	//cout << "������ Food �����." << endl;
	counter--;
}



//Work
Food* Food::Add_Food(Food* food_mas)
{
	Food* base_error = food_mas;
	int counter = food_mas[0].Get_Counter();
	Food* base_cpy = new Food[counter+1];
	memcpy(base_cpy, food_mas, sizeof(Food) * counter);
	delete[] food_mas;

	std::string name_value;
	cout << "������� ��������:" << endl;
	cin >> name_value;
	base_cpy[counter].Set_Name(name_value);

	cout << "�������� ��� ��������" << endl;
	cout << "1- �������, 2-�������, 3-��������" << endl;
	int tmp;
	cin >> tmp;
	if (tmp == 1) base_cpy[counter].food_type = Product_Bulochka;
	else if (tmp == 2)  base_cpy[counter].food_type = Product_Pirojok;
	else if (tmp == 3) base_cpy[counter].food_type = Product_Pirojnoe;
	else
	{
		cout << "������ �����!" << endl;
		return base_error;
	}

	cout << "�������� ��� ��������" << endl;
	double weight_value;
	for (;;)
	{
		try
		{
			cin >> weight_value;
			if (weight_value < 0) throw - 1;
		}
		catch (...)
		{
			continue;
		}
		break;
	}
	base_cpy[counter].Set_Weight(weight_value);

	cout << "�������� ���-�� ��������" << endl;
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

	cout << "�������� ���� ��������" << endl;
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
		cout << "�������� ���� �������� ����� ������" << endl;
		int a, b, c;
		cin >> a >> b >> c;
		if (a <= 0 || b <= 0 || c <= 0)
		{
			cout << "�������� ����" << endl;
			continue;
		}
		if (b > 12)
		{
			cout << "�������� ����" << endl;
			continue;
		}
		else
		{
			if (b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12)
			{
				if (c > 31) {
					cout << "�������� ����" << endl;
					continue;
				}
			}
			else if (b == 4 || b == 6 || b == 9 || b == 11)
			{
				if (c > 30) {
					cout << "�������� ����" << endl;
					continue;
				}
			}
			else if (b == 2)
			{
				if (a % 4 != 0)
				{
					if (c > 28) {
						cout << "�������� ����" << endl;
						continue;
					}
				}
				else
				{
					if (c > 29)
					{
						cout << "�������� ����" << endl;
						continue;
					}
				}
			}
		}
		base_cpy[counter].Set_Date(class Date(a, b, c));
		break;
	}

	return base_cpy;
}

Food* Food::Add1_Food(Food* food_mas) // ����� ������� ����� � ���������� (������ Add_Food)
{
	Food* base_error = food_mas;
	int counter = food_mas[0].Get_Counter();
	Food* base_cpy = new Food[counter + 1];
	memcpy(base_cpy, food_mas, sizeof(Food) * counter);
	delete[] food_mas;

	std::cout << "������� ����� ������ ��������� ������:" << std::endl;
	std::cout << "�������� ���������� ���� ��� ����� ���� ������_����_��������(1-3) ���." << std::endl;
	std::cin >> base_cpy[counter];

	return base_cpy;
}

//Work
void Food::Print_Info(Food* base)
{
	printf("��������    ���       ���   ���-��    ����   ����\n");
	printf("-----------------------------------------------------------------------\n");
	for (int i = 0; i < base->Get_Counter(); i++)
	{
		cout << base[i] << endl;
	}
}
//Work
void Food::Exit(Food* base)
{
	ofstream file;
	file.open("food_base.txt", ios_base::trunc);
	for (int i = 0; i < counter; i++)
	{
		file << base[i].Name() << endl;
		file << base[i].Food_Type() << endl;
		file << base[i].Weight() << endl;
		file << base[i].Number() << endl;
		file << base[i].Price() << endl;
		file << base[i].Get_Date().Year() << " " << base[i].Get_Date().Month() << " " << base[i].Get_Date().Day() << endl;
	}
}

void Food::Name_Search(Food* base)
{
	string tmp;
	cout << "������� ������� �����." << endl;
	cin >> tmp;
	printf("��������    ���       ���   ���-��    ����   ����\n");
	printf("-----------------------------------------------------------------------\n");
	for (int i = 0; i < base[0].counter; i++)
	{
		if (tmp == base[i].Name())
		{
			cout << base[i] << endl;
		}
	}
}

void Price_Sort(Food* base)
{
	int counter = base[0].Get_Counter();
	for (int i = 0; i < counter - 1; i++)
	{
		for (int j = 0; j < counter - i - 1; j++)
		{
			if (base[j].Price() < base[j + 1].Price())
			{
				swap(base[j], base[j + 1]);
				base->Counter();
			}
		}
	}
}

string Food::Food_Type_ToString()
{
	if (food_type == Product_Bulochka) { return "�������"; }
	if (food_type == Product_Pirojok) { return "�������"; }
	return "��������";
}

bool operator == (Food& food1, Food& food2)
{
	if (food1.Name() != food2.Name()) return false;
	if (food1.food_type != food2.food_type) return false;
	if (food1.weight != food2.weight) return false;
	if (food1.Get_Quantity() != food2.Get_Quantity()) return false;
	if (food1.Get_Price() != food2.Get_Price()) return false;
	if (food1.Date().Date_To_String() != food2.Date().Date_To_String()) return false;
	return true;
}

std::ostream& operator <<(std::ostream& out, Food& food) {
	
	out << food.Food::Name() << ' ' << food.Food_Type_ToString() << "     " << food.weight << "     " << food.Get_Quantity() << "     " << food.Get_Price() << "     " << food.Date().Date_To_String();
	return out;
}

Food& Food::operator= (Food food1)
{
	if (*this == food1) return *this;
	this->Set_Name(food1.Get_Name());
	this->Set_Quantity(food1.Get_Quantity());
	this->Set_Price(food1.Get_Price());
	this->Set_Date(food1.Get_Date());
	this->Set_Food_Type(food1.Food_Type());
	this->Set_Weight(food1.Weight());
	return *this;
}

std::istream& operator >>(std::istream& in, Food& food1)
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
		std::cout << "������ ����� ����������. ���������� ����������� ��������." << std::endl;
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
		std::cout << "������ ����� ����. ���������� ����������� ��������." << std::endl;
		food1.Set_Price(100);
	}
	int a, b, c;
	try
	{
		in >> a >> b >> c;
		if (a <= 0 || b <= 0 || c <= 0)
		{
			cout << "�������� ����" << endl;
			throw -1;
		}
		if (b > 12)
		{
			cout << "�������� ����" << endl;
			throw - 1;
		}
		else
		{
			if (b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12)
			{
				if (c > 31) {
					cout << "�������� ����" << endl;
					throw - 1;
				}
			}
			else if (b == 4 || b == 6 || b == 9 || b == 11)
			{
				if (c > 30) {
					cout << "�������� ����" << endl;
					throw - 1;
				}
			}
			else if (b == 2)
			{
				if (a % 4 != 0)
				{
					if (c > 28) {
						cout << "�������� ����" << endl;
						throw - 1;
					}
				}
				else
				{
					if (c > 29)
					{
						cout << "�������� ����" << endl;
						throw - 1;
					}
				}
			}
		}
		food1.Common::Set_Date(a, b, c);
	}
	catch (...)
	{

		food1.Common::Set_Date(2000,1,1);
	}
	
	in >> a;
	food1.Set_Food_Type(a);
	try
	{
		in >> tmp_price;
		if (tmp_price <= 0) throw - 1;
		food1.Set_Weight(tmp_price);
	}
	catch (...)
	{
		std::cout << "������ ����� ����. ��������� ���������� ���." << std::endl;
		food1.Set_Weight(1);
	}
	return in;
}