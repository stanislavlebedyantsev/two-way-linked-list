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
#include "input.h"
#include "print.h"
#include "del.h"
#include "edit.h"
#include "search.h"
#include "sort.h"
#include "filework.h"
#include "filt.h"
#include "check_input.h"

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

void ClearMem();											//очистка памяти перед выходом

void menu() {	//меню ввода
	system("cls");
	cout << "1 - Меню ввода элементов\n";
	cout << "2 - Вывод элементов\n";
	cout << "3 - Удаление элемента\n";
	cout << "4 - Редактирование элемента\n";
	cout << "5 - Поиск элемента\n";
	cout << "6 - Сортировка элементов\n";
	cout << "7 - Фильтрация элементов по условию\n";
	cout << "0 - Меню работ с файлами\n";
	cout << "ESC для выхода...\n";
	switch (_getch()) {
		case 27: {
			if (value != 0) {
				cout << "Выбран выход!\n";
				ClearMem();
				exit(0);
			}
			else {
				cout << "Выбран выход!\n";
				exit(0);
			}

		}
		case 49: {
			do
			{
				system("cls");
				cout << "1 - Ввод в конец списка\n";
				cout << "2 - Ввод в начало списка\n";
				cout << "3 - Ввод в выбранную позицию списка\n";
				cout << "0 - Выход в меню\n";
				switch (_getch())
				{
				case 49: {
					input(1);
					break;
				}
				case 50: {
					input(2);
					break;
				}
				case 51: {
					input(3);
					break;
				}
				case 48: {
					menu();
					break;
				}
				default:
					cout << "Нет выбранного пункта меню! Повторите попытку!\n";
					system("pause");
				}
			} while (1);
			break;
		}
		case 50: {
			system("cls");
			if (value == 0) {
				cout << "Нет записей!\n";
				system("pause");
			}
			else {
				PrintTable();
				system("pause");
			}
			break;
		}
		case 51: {
			system("cls");
			if (value == 0) {
				cout << "Нет записей!\n";
				system("pause");
			}
			else {
				
				DelElem();
			}
			break;
		}
		case 52: {
			system("cls");
			if (value == 0) {
				cout << "Нет записей!\n";
				system("pause");
			}
			else {
				system("cls");
				int pos;
				PrintTable();
				cout << "Введите номер элемента для редактирования( 0 - Выход в меню): ";
				cin >> pos;
				while (check_input(9) != 1 || pos > value || pos < 0) {
					cout << "Номер элемента больше размера списка! Повторите попытку: ";
					cin.clear();
					cin.ignore(100000000, '\n');
					cin >> pos;
				}
				if (pos != 0) {
					edit(pos);
				}
			}
			break;
		}
		case 53: {
			system("cls");
			if (value == 0) {
				cout << "Нет записей!\n";
				system("pause");
			}
			else {
				search();
			}
			break;
		}
		case 54: {
			system("cls");
			if (value == 0) {
				cout << "Нет записей!\n";
				system("pause");
			}
			else {
				sort();
			}
			break;
		}
		case 55: {
			system("cls");
			if (value == 0) {
				cout << "Нет записей!\n";
				system("pause");
			}
			else {
				Filt_choise();
			}
			break;
		}
		case 48: {
			FileWork();
			break;
		}
		default: {
			cout << "\nНет выбранного пункта меню! Повторите попытку!\n";
			system("pause");
			break;
		}
	}
	menu();
}

void ClearMem() {		//очистка памяти перед выходом
	do {
		_hotel *buff = head;
		head = head->next;
		free(buff);
	} while (head != NULL);
}