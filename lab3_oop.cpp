#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "date.h"
#include "food.h"
#include "food1.h"
#include <string>
#include <vector>
#include <time.h>


int Food::counter = 0;
int Food1::counter = 0;
using namespace std;
//Work
Food* Get_Base()
{
    ifstream file;
    file.open("food_base.txt");
    FILE* ptrFile = fopen("food_base.txt", "rb");
    Food* ptr = new Food[0];
    Food* ptr_tmp;
    int lenght = 0;
    for (;;)
    {
        char* buff = new char[30];
        file.getline(buff, 30);
        if (strcmp(buff, "") == 0) break;
        ptr_tmp = new Food[lenght + 1];
        memcpy(ptr_tmp, ptr, sizeof(Food) * lenght);
 /*       delete[] ptr;*/

        ptr = ptr_tmp;
        
        char* tmp = new char[strlen(buff)+1];
        strcpy(tmp, buff);
        string str = tmp;
        ptr[lenght].Set_Name(str);

        int tmp_prod;
        file >> tmp_prod;
        ptr[lenght].Set_Food_Type(tmp_prod);

        double d_tmp;
        file >> d_tmp;
        ptr[lenght].Set_Weight(d_tmp);

        file >> tmp_prod;
        ptr[lenght].Set_Number(tmp_prod);

        file >> d_tmp;
        ptr[lenght].Set_Price(d_tmp);

        int a, b, c;
        file >> a >> b >> c;
        Date tmp_date = Date(a, b, c);
        ptr[lenght].Set_Date(tmp_date);

        //ptr[lenght].Counter();

        char zero;
        file >> zero;
        file.seekg(-1, ios::cur);
        lenght++;
    }
    ptr->Counter(lenght);
    return ptr;
}

Food1* Get_Base1()
{
    ifstream file;
    file.open("food_base1.txt");
    FILE* ptrFile = fopen("food_base1.txt", "rb");
    Food1* ptr = new Food1[0];
    Food1* ptr_tmp;
    int lenght = 0;
    for (;;)
    {
        char* buff = new char[30];
        file.getline(buff, 30);
        if (strcmp(buff, "") == 0) break;
        ptr_tmp = new Food1[lenght + 1];
        memcpy(ptr_tmp, ptr, sizeof(Food) * lenght);
        ptr = ptr_tmp;

        char* tmp = new char[strlen(buff) + 1];
        strcpy(tmp, buff);
        string str = tmp;
        ptr[lenght].Set_Name(str);

        int tmp_prod;
        file >> tmp_prod;
        ptr[lenght].Set_Number(tmp_prod);

        double d_tmp;
        file >> d_tmp;
        ptr[lenght].Set_Price(d_tmp);

        int a, b, c;
        file >> a >> b >> c;
        Date tmp_date = Date(a, b, c);
        ptr[lenght].Set_Date(tmp_date);


        file >> a >> b >> c;
        Date tmp_date1 = Date(a, b, c);
        ptr[lenght].Set_SellDate(tmp_date1);

 /*       ptr[lenght].Counter1();*/

        char zero;
        file >> zero;
        file.seekg(-1, ios::cur);
        lenght++;
    }
    ptr->Counter1(lenght);
    return ptr;
}

void Date_Search(Food* ptr)
{
    cout << "Выберите дату продукта через пробел" << endl;
    int a, b, c;
    cin >> a >> b >> c;
    Date new_date = Date(a, b, c);
    printf("Название    Тип       Вес   Кол-во    Цена   Дата\n");
    printf("-----------------------------------------------------------------------\n");
    for (int i = 0; i < ptr[0].Get_Counter(); i++)
    {
        if (ptr[i].Get_Date() == new_date)
        {
            cout << ptr[i] << endl;
        }
    }
}

void Date_Search1(Food1* ptr)
{
    cout << "Выберите дату продукта через пробел" << endl;
    int a, b, c;
    cin >> a >> b >> c;
    Date new_date = Date(a, b, c);
    printf("Название    Тип       Вес   Кол-во    Цена   Дата\n");
    printf("-----------------------------------------------------------------------\n");
    for (int i = 0; i < ptr[0].Get_Counter(); i++)
    {
        if (ptr[i].Create_Date() == new_date)
        {
            cout << ptr[i] << endl;
        }
    }
}

void SrokGodnosi(Food1* ptr1, Food* ptr)
{
    /*Food* new_mas = new Food[0];
    Food1* new_mas1 = new Food1[0];*/
    vector<Food> vec;
    vector<Food1> vec1;
    int hours;
    for (;;)
    {
        
        try {
            cin >> hours;
            if (hours <= 0) throw - 1;
        }
        catch (...)
        {
            continue;
        }
        break;
    }
    struct tm* u;
    //system("chcp 1251");
    //system("cls");
    const time_t timer = time(NULL);
    u = localtime(&timer);
    int cur_year = u->tm_year+1900;
    int cur_month = u->tm_mon + 1;
    int cur_day = u->tm_mday;
    long long cur_hours = cur_year * 8766 + cur_month * 730 + cur_day * 24;
    int lenght = 0;
    int lenght1 = 0;
    for (int i = 0; i < ptr[0].Get_Counter(); i++)
    {
        long long tmp = ptr[i].Get_Date().Year() * 8766 + ptr[i].Get_Date().Month() * 730 + ptr[i].Get_Date().Day() * 24;
        if (cur_hours - tmp > hours)
        {
            /*Food* tmp = new Food[lenght + 1];
            memcpy(tmp, new_mas, sizeof(Food) * lenght);
            delete[] new_mas;
            new_mas = tmp;
            new_mas[lenght] = ptr[i];
            lenght++;*/
            vec.push_back(ptr[i]);
        }
    }
    for (int i = 0; i < ptr1[0].Get_Counter(); i++)
    {
        long long tmp = ptr1[i].Get_Date().Year() * 8766 + ptr1[i].Get_Date().Month() * 730 + ptr1[i].Get_Date().Day() * 24;
        if (cur_hours - tmp > hours)
        {
            /*Food1* tmp = new Food1[lenght1 + 1];
            memcpy(tmp, new_mas1, sizeof(Food1) * lenght1);
            delete[] new_mas1;
            new_mas1 = tmp;
            new_mas1[lenght1] = ptr1[i];
            lenght1++;*/
            vec1.emplace_back(ptr1[1]);
        }
    }
    /*for (int it = 0; it < lenght; it++)
        std::cout << new_mas[it] << std::endl;
    for (int it = 0; it < lenght1; it++)
        std::cout << new_mas1[it] << std::endl;*/
    for (auto it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << endl;
    for (auto it = vec1.begin(); it != vec1.end(); ++it)
        std::cout << *it << endl;
}


int main()
{
    setlocale(LC_ALL, "Russian");

    printf("1.Добавить новый продукт.\n");
    printf("2.Распечатать инфомацию.\n");
    printf("3.Найти ппродукт по названию.\n");
    printf("4.Сортировать по цене.\n");
    printf("5.Найти продукт по дате.\n");
    printf("6.Добавить новый продукт в Food1.\n");
    printf("7.Распечатать инфомацию из Food1.\n");
    printf("8.Найти продукт по названию в Food1.\n");
    printf("9.Сортировать по цене в Food1.\n");
    printf("10.Найти продукт по дате создания в Food1.\n");
    printf("11.Срок годности.\n");
    printf("0.выйти из программы.\n");

    Food* ptr = new Food[0];
    Food1* ptr1 = new Food1[0];
    ptr = Get_Base();
    ptr1 = Get_Base1();
    int ch = 0;
    for (;;)
    {
        printf("Выберите число:\n");
        std::cin >> ch;
        switch (ch)
        {
        case 1:
            ptr = ptr->Add1_Food(ptr);
            break;
        case 2:
            ptr->Print_Info(ptr);
            break;
        case 3:
            ptr->Name_Search(ptr);
            break;
        case 4:
            Price_Sort(ptr);
            break;
        case 5:
            Date_Search(ptr);
            break;
        case 6:
            ptr1 = ptr1->Add1_Food(ptr1);
            break;
        case 7:
            ptr1->Print_Info(ptr1);
            break;
        case 8:
            ptr1->Name_Search(ptr1);
            break;
        case 9:
            Price_Sort(ptr1);
            break;
        case 10:
            Date_Search1(ptr1);
            break;
        case 11:
            SrokGodnosi(ptr1, ptr);
            break;
         
        case 0:
            ptr->Exit(ptr);
            ptr1->Exit(ptr1);
            return 0;
        default:
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Такого пунка в меню нет!!1!" << endl;
            break;
        }
    }
    return 0;

}

