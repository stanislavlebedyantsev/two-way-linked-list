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
#include "check_input.h"
#include "input.h"
#include "add_last.h"

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

void add_mid(_hotel *temp);									//добавление в выбранную позицию
void add_head(_hotel *temp);								//функция добавления в начало списка

void add_mid(_hotel *temp) {					//функция добавления в выбранную позицию
	if (head == NULL && tail == NULL) {
		cout << "Список пуст, вставка сделана в начало!\n";
		add_head(temp);
		system("pause");
	}
	else {
		int pos;
		cout << "Введите число больше 1 и не больше " << value << ": ";
		cin >> pos;
		while (check_input(9) != 1 || pos <= 0 || pos > value) {
			cout << "Введена неверная позиция! Повторите попытку!\n";
			cin.clear();
			cin.ignore(100000000, '\n');
			cin >> pos;
		}
		if (pos == 1) {
			add_head(temp);
		}
		else if (pos == value) {
			add_last(temp);
		}
		else {
			_hotel *buff = head;
			int score = 0;
			pos--;
			do {
				if (score == pos) {
					if (buff->prev != NULL) {
						buff->prev->next = temp;
					}
					if (buff->next != NULL) {
						buff->next->prev = temp;
					}
					temp->next = buff;
					temp->prev = buff->prev;
					break;
				}
				else {
					buff = buff->next;
					score++;
				}
			} while (buff != NULL);
		}
	}

}

void add_head(_hotel *temp) {					//функция добавления в начало списка
	if (head == NULL && tail == NULL) {
		tail = head = temp;
		temp->next = NULL;
		temp->prev = NULL;
	}
	else {
		temp->prev = NULL;
		head->prev = temp;
		temp->next = head;
		head = temp;
	}
}

void input(int add_type) {	//ввод элементов с клавиатуры
	system("cls");
	bool flag = false;
	_hotel *hotel = (_hotel*)malloc(sizeof(_hotel));
	do
	{
		num = 0;
		cout << "Введите номер номера в отеле(больше 0 и не более 500): ";
		cin >> num;
		if (check_input(1) == -1) {
			cout << "Введено неверное значение!\n";
			cin.clear();
			cin.ignore(100000000, '\n');

		}
	} while (check_input(1) != 1);
	hotel->num = num;
	cin.clear();
	cin.ignore(100000000, '\n');
	do
	{
		arr[0] = 0, arr[1] = 0, arr[2] = 0;
		cout << "Введите дату в формате dd/mm/yyyy: ";
		cin >> arr[0] >> ch >> arr[1] >> ch2 >> arr[2];
		if (check_input(2) == -1) {
			cout << "Введено неверное значение даты!\n";
			cin.clear();
			cin.ignore(100000000, '\n');
		}
	} while (check_input(2) != 1);
	hotel->date_base.day = arr[0], hotel->date_base.month = arr[1], hotel->date_base.year = arr[2];
	cin.clear();
	cin.ignore(100000000, '\n');
	do
	{
		fflush(stdin);
		cout << "Введите фамилию постояльца(не превышает 29 символов): ";
		gets_s(str);
		if (check_input(3) == -1) {
			cout << "Превышено доступное количество символов или введена пустая строка. Повторите ввод!\n";
			fflush(stdin);
		}
		else if (check_input(3) == 1 && check_input(12) == -1) {
			cout << "Строка не может состоять только из пробелов! Повторите ввод!\n";
			fflush(stdin);
		}
	} while (check_input(3) != 1 || check_input(12) != 1);
	strcpy(hotel->name, str);
	do
	{
		num = 0;
		fflush(stdin);
		cout << "Выберите из предложенных вариантов способ оплаты\n" << "1 - наличные\n2 - карта\n3 - ApplePay\n4 - SamsungPay\n5 - GooglePay\n";
		cin >> num;
		if (check_input(4) == -1) {
			cout << "Неверное значение! Повторите ввод\n";
			cin.clear();
			cin.ignore(100000000, '\n');
		}

	} while (check_input(4) != 1);
	switch (num) {
		case 1: {
			strcpy(hotel->typepay, "наличные");
			break;
		}
		case 2: {
			strcpy(hotel->typepay, "карта");
			break;
		}
		case 3: {
			strcpy(hotel->typepay, "ApplePay");
			break;
		}
		case 4: {
			strcpy(hotel->typepay, "SamsungPay");
			break;
		}
		case 5: {
			strcpy(hotel->typepay, "GooglePay");
			break;
		}
	}
	cin.clear();
	cin.ignore(100000000, '\n');
	do
	{
		num = 0;
		cout << "Введите цену номера(больше 0 и не более 1000): ";
		cin >> num;
		if (check_input(5) == -1) {
			cout << "Введено неверное значение цены!\n";
			cin.clear();
			cin.ignore(100000000, '\n');
		}
	} while (check_input(5) != 1);
	hotel->price = num;
	cin.clear();
	cin.ignore(100000000, '\n');
	do
	{
		fflush(stdin);
		cout << "Введите тип номера(не превышает 11 символов): ";
		gets_s(str);
		if (check_input(6) == -1) {
			cout << "Превышено доступное количество символов или введена пустая. Повторите ввод!\n";
			fflush(stdin);
		}
		else if (check_input(6) == 1 && check_input(12) == -1) {
			cout << "Строка не может состоять только из пробелов! Повторите ввод!\n";
			fflush(stdin);
		}
	} while (check_input(6) != 1 || check_input(12) != 1);
	strcpy(hotel->numtype, str);
	do
	{
		num = 0;
		cout << "Введите количество комнат(больше 0 и не более 3): ";
		cin >> num;
		if (check_input(7) == -1) {
			cout << "Введено неверное значение количества комнат!\n";
			cin.clear();
			cin.ignore(100000000, '\n');
		}
	} while (check_input(7) != 1);
	hotel->roomnum = num;
	cin.clear();
	cin.ignore(100000000, '\n');
	do
	{
		fflush(stdin);
		cout << "Введите тип брони(не превышает 17 символов): ";
		gets_s(str);
		if (check_input(8) == -1) {
			cout << "Превышено доступное количество символов или введена пустая строка. Повторите ввод!\n";
			fflush(stdin);
		}
		else if (check_input(8) == 1 && check_input(12) == -1) {
			cout << "Строка не может состоять только из пробелов! Повторите ввод!\n";
			fflush(stdin);
		}
	} while (check_input(8) != 1 || check_input(12) != 1);
	strcpy(hotel->bookingtype, str);
	value++;
	system("pause");
	system("cls");
	switch (add_type) {
		case 1: {
			add_last(hotel);
			break;
		}
		case 2: {
			add_head(hotel);
			break;
		}
		case 3: {
			add_mid(hotel);
			break;
		}
	}
}