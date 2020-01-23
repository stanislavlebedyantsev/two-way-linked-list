#define _CRT_SECURE_NO_WARNINGS 
#include "stdafx.h"
#include <time.h>
#include <cstdlib>
#include <cstdio>
#include <string.h>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <tchar.h>
#include <clocale>
#include <iomanip>
#include "sort.h"
#include "check_input.h"
#include "print.h"

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

extern _hotel *head;										//указатель на начало списка
extern _hotel *tail;										//указатель на конец списка

void sort_process(int sort_by, int sort_direction);			//функция процесса сортировки
void swap(_hotel *cur, _hotel *next);						//смена узлов
bool condition(_hotel *cur, _hotel *next, int sort_by, int sort_direction);		//сравнение узлов по направлению и полю

void sort() {			//функция сортировки
	_hotel *buff = head;
	int num_field = 0, num_field2 = 0;
	PrintTable();
	cout << "Выберете поле для сортировки: \n";
	cout << "1 - Номер в отеле\n";
	cout << "2 - Дата бронирования\n";
	cout << "3 - Фамилия, имя, отчество \n";
	cout << "4 - Способ оплаты \n";
	cout << "5 - Цена \n";
	cout << "6 - Тип номера \n";
	cout << "7 - Количество комнат \n";
	cout << "8 - Тип бронирования \n";
	cout << "0 - Выход из сортировки\n";
	cin >> num_field;
	while (check_input(9) != 1 || num_field > 8 || num_field < 0) {
		cout << "Введено неверное значение! Повторите ввод!\n";
		cin.clear();
		cin.ignore(100000000, '\n');
		cin >> num_field;
	}
	if (num_field != 0) {
		system("cls");
		PrintTable();
		cout << "Направление сортировки\n" << "1 - По возрастанию(от A до Z)\n" << "2 - По убыванию(от Z до А)\n" << "0 - Выйти из меню сортировки\n";
		cin >> num_field2;
		while (check_input(9) != 1 || num_field2 < 0 || num_field2 > 2) {
			cout << "Введено неверное значение! Повторите ввод!\n";
			cin.clear();
			cin.ignore(100000000, '\n');
			cin >> num_field2;
		}
		sort_process(num_field, num_field2);
	}
}

void sort_process(int sort_by, int sort_direction) {		//процесс сортировки
	for (_hotel *i = head; i != NULL; i = i->next) {
		for (_hotel *j = head; j != NULL; j = j->next) {
			if (condition(i, j, sort_by, sort_direction)) {
				swap(i, j);
			}
		}
	}
}

void swap(_hotel *cur, _hotel *next) {				//сортировка пузырьком
	int num = cur->num;
	int day = cur->date_base.day;
	int month = cur->date_base.month;
	int year = cur->date_base.year;
	char name[30];
	strcpy(name, cur->name);
	char typepay[15];
	strcpy(typepay, cur->typepay);
	int price = cur->price;
	char numtype[30];
	strcpy(numtype, cur->numtype);
	int roomnum = cur->roomnum;
	char bookingtype[30];
	strcpy(bookingtype, cur->bookingtype);
	//
	cur->num = next->num;
	next->num = num;
	//
	cur->date_base.day = next->date_base.day;
	next->date_base.day = day;
	//
	cur->date_base.month = next->date_base.month;
	next->date_base.month = month;
	//
	cur->date_base.year = next->date_base.year;
	next->date_base.year = year;
	//
	strcpy(cur->name, next->name);
	strcpy(next->name, name);
	//
	strcpy(cur->typepay, next->typepay);
	strcpy(next->typepay, typepay);
	//
	cur->price = next->price;
	next->price = price;
	//
	strcpy(cur->numtype, next->numtype);
	strcpy(next->numtype, numtype);
	//
	cur->roomnum = next->roomnum;
	next->roomnum = roomnum;
	//
	strcpy(cur->bookingtype, next->bookingtype);
	strcpy(next->bookingtype, bookingtype);

}


bool condition(_hotel *cur, _hotel *next, int sort_by, int sort_direction) {		//сравнение узлов по направлению и полю
	return (
		(sort_direction == 1 && sort_by == 1 && cur->num < next->num) || (sort_direction == 2 && sort_by == 1 && cur->num > next->num) ||

		(sort_direction == 1 && sort_by == 2 && (cur->date_base.year < next->date_base.year || (cur->date_base.year == next->date_base.year && (cur->date_base.month < next->date_base.month)) || (cur->date_base.year == next->date_base.year && cur->date_base.month == next->date_base.month && (cur->date_base.day < next->date_base.day)))) ||
		(sort_direction == 2 && sort_by == 2 && (cur->date_base.year > next->date_base.year || (cur->date_base.year == next->date_base.year && (cur->date_base.month > next->date_base.month)) || (cur->date_base.year == next->date_base.year && cur->date_base.month == next->date_base.month && (cur->date_base.day > next->date_base.day)))) ||


		(sort_direction == 1 && sort_by == 3 && strcmp(cur->name, next->name) < 0) || (sort_direction == 2 && sort_by == 3 && strcmp(cur->name, next->name) > 0) ||
		(sort_direction == 1 && sort_by == 4 && strcmp(cur->typepay, next->typepay) < 0) || (sort_direction == 2 && sort_by == 4 && strcmp(cur->typepay, next->typepay) > 0) ||
		(sort_direction == 1 && sort_by == 5 && cur->price < next->price) || (sort_direction == 2 && sort_by == 5 && cur->price > next->price) ||
		(sort_direction == 1 && sort_by == 6 && strcmp(cur->numtype, next->numtype) < 0) || (sort_direction == 2 && sort_by == 6 && strcmp(cur->numtype, next->numtype) > 0) ||
		(sort_direction == 1 && sort_by == 7 && cur->roomnum < next->roomnum) || (sort_direction == 2 && sort_by == 7 && cur->roomnum > next->roomnum) ||
		(sort_direction == 1 && sort_by == 8 && strcmp(cur->bookingtype, next->bookingtype) < 0) || (sort_direction == 2 && sort_by == 8 && strcmp(cur->bookingtype, next->bookingtype) > 0)
		);
}