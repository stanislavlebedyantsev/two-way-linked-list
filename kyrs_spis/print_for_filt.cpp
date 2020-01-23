#define _CRT_SECURE_NO_WARNINGS 
#include "stdafx.h"
#include <time.h>
#include <cstdlib>
#include <cstdio>
#include <string.h>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <clocale>
#include <iomanip>
#include "print_for_filt.h"


using namespace std;

extern struct _hotel {
	int num;												//номер
	struct date
	{
		int day;
		int month;
		int year;
	}date_base;												//дата брони
	char name[30];											//Фамилия постояльца
	char typepay[15];										//способ оплаты
	int price;												//цена
	char numtype[12];										//тип номера
	int roomnum;											//количество комнат
	char bookingtype[18];									//тип брони
	struct _hotel *next;									//указатель на следующий элемент
	struct _hotel *prev;									//указатель на предыдущий элемент

};

void print_for_filt(_hotel *buff, int i, int kol) {		//функция вывода данных для фильтрации
	if (kol == 0) {
		cout << "| № | Номер в отеле | Дата бронирования |       Фамилия постояльца     | Способ оплаты | Цена номера | Тип номера | Количество комнат | Тип бронирования |\n";
	}
	cout << "|" << setw(3) << i;
	cout << '|' << setw(15) << buff->num << '|';
	if (buff->date_base.day < 10) {
		cout << setw(10) << 0 << buff->date_base.day << '/';
	}
	else {
		cout << setw(11) << buff->date_base.day << '/';
	}
	if (buff->date_base.month < 10) {
		cout << 0 << buff->date_base.month;
	}
	else {
		cout << buff->date_base.month;
	}
	cout << '/' << buff->date_base.year << '|';
	cout << setw(30) << buff->name << '|';
	cout << setw(15) << buff->typepay << '|';
	cout << setw(13) << buff->price << '|';
	cout << setw(12) << buff->numtype << '|';
	cout << setw(19) << buff->roomnum << '|';
	cout << setw(18) << buff->bookingtype << '|';
	cout << endl;
}
