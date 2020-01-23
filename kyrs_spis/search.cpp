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
#include "search.h"
#include "check_input.h"
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

extern _hotel *head;										//указатель на начало списка
extern _hotel *tail;										//указатель на конец списка

void search() {			//функция поиска записи
	do
	{
		system("cls");
		_hotel *buff = head;
		int score = 0;
		int num_field = 0;
		cout << "Вы вошли в меню поиска! Выберете по какому полю будете искать:\n";
		cout << "1 - Номер в отеле\n";
		cout << "2 - Дата бронирования\n";
		cout << "3 - Фамилия постояльца \n";
		cout << "4 - Способ оплаты \n";
		cout << "5 - Цена \n";
		cout << "6 - тип номера \n";
		cout << "7 - Количество комнат \n";
		cout << "8 - Тип бронирования \n";
		cout << "0 - Выход из поиска\n";
		cin >> num_field;
		if (cin.good() && num_field != 0) {
			cin.clear();
			cin.ignore(100000000, '\n');
			switch (num_field)
			{
			case 1: {
				num = 0;
				cout << "Введите номер комнаты в отеле(больше 0 и не больше 500): ";
				cin >> num;
				while (check_input(1) != 1) {
					cout << "Неверный ввод! Повторите попытку: ";
					cin.clear();
					cin.ignore(100000000, '\n');
					cin >> num;
				}

				break;
			}
			case 2: {
				arr[0] = 0, arr[1] = 0, arr[2] = 0;
				cout << "Введите дату в формате dd/mm/yyyy: ";
				cin >> arr[0] >> ch >> arr[1] >> ch2 >> arr[2];
				while (check_input(2) != 1 || check_input(12) != 1) {
					cout << "Неверный ввод! Повторите попытку: ";
					cin.clear();
					cin.ignore(100000000, '\n');
					cin >> arr[0] >> ch >> arr[1] >> ch2 >> arr[2];
				}
				break;
			}
			case 3: {
				fflush(stdin);
				cin.clear();
				cin.ignore(100000000, '\n');
				cout << "Введите фамилию постояльца(не превышает 29 символов): ";
				gets_s(str);
				while (check_input(3) != 1) {
					cout << "Неверный ввод! Повторите попытку: ";
					fflush(stdin);
					gets_s(str);
				}
				num = 0;
				break;
			}
			case 4: {
				num = 0;
				cout << "Выберите из предложенных вариантов новый способ оплаты\n" << "1 - Наличные\n2 - Карта\n3 - ApplePay\n4 - SamsungPay\n5 - GooglePay\n";
				cin >> num;
				while (check_input(4) != 1) {
					cout << "Неверный ввод! Повторите попытку: ";
					cin.clear();
					cin.ignore(100000000, '\n');
					cin >> num;
				}
				switch (num) {
				case 1: {
					strcpy(str, "Наличные");
					break;
				}
				case 2: {
					strcpy(str, "Карта");
					break;
				}
				case 3: {
					strcpy(str, "ApplePay");
					break;
				}
				case 4: {
					strcpy(str, "SamsungPay");
					break;
				}
				case 5: {
					strcpy(str, "GooglePay");
					break;
				}
				}
				break;
			}
			case 5: {
				num = 0;
				cout << "Введите цену номера(больше 0 и не более 1000): ";
				cin >> num;
				while (check_input(5) != 1) {
					cout << "Неверный ввод! Повторите попытку: ";
					cin.clear();
					cin.ignore(100000000, '\n');
					cin >> num;
				}
				break;
			}
			case 6: {
				fflush(stdin);
				getchar();
				cout << "Введите тип номера(не превышает 11 символов): ";
				gets_s(str);
				while (check_input(6) != 1 || check_input(12) != 1) {
					cout << "Неверный ввод! Повторите попытку: ";
					fflush(stdin);
					gets_s(str);
				}
				num = 0;
				break;
			}
			case 7: {
				num = 0;
				cout << "Введите количество комнат(больше 0 и не более 3) : ";
				cin >> num;
				while (check_input(7) != 1) {
					cout << "Неверный ввод! Повторите попытку: ";
					cin.clear();
					cin.ignore(100000000, '\n');
					cin >> num;
				}
				break;
			}
			case 8: {
				fflush(stdin);
				getchar();
				cout << "Введите тип бронирования(не превышает 17 символов): ";
				gets_s(str);
				while (check_input(8) != 1 || check_input(12) != 1) {
					cout << "Неверный ввод! Повторите попытку: ";
					fflush(stdin);
					gets_s(str);
				}
				num = 0;
				break;
			}
			default:
				cout << "Выбранно несуществующее поле! Повторите попытку\n";
				system("pause");
				break;
			}
			if (num_field < 9 && num_field > 0) {
				int kol = 0;
				do
				{
					if ((num == buff->num && num_field == 1) || (arr[0] == buff->date_base.day && arr[1] == buff->date_base.month && arr[2] == buff->date_base.year && num_field == 2) || (num == buff->price && num_field == 5) || (num == buff->roomnum && num_field == 7)) {
						print_for_filt(buff, score + 1, kol);
						kol++;
						score++;
						buff = buff->next;
					}
					else if ((strcmp(str, buff->name) == 0 && num_field == 3) || (strcmp(str, buff->typepay) == 0 && num_field == 4) || (strcmp(str, buff->numtype) == 0 && num_field == 6) || (strcmp(str, buff->bookingtype) == 0 && num_field == 8)) {
						print_for_filt(buff, score + 1, kol);
						kol++;
						score++;
						buff = buff->next;
					}
					else {
						score++,
						buff = buff->next;
					}
				} while (buff != NULL);
				if (kol == 0) {
					cout << "Ничего не было найдено!\n";
					system("pause");
				}
				else {
					cout << "\nПоиск окончен!\n";
					system("pause");
				}
			}
		}
		else if (!cin.good()) {
			cout << "Вместо числа введен символ! Повторите попытку!\n ";
			cin.clear();
			cin.ignore(100000000, '\n');
			system("pause");
		}
		else {
			break;
		}
	} while (1);
}