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
#include "del.h"
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
	char name[30];											//‘амили€ посто€льца
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

void DelElem() {		//удаление элемента из списка
	system("cls");
	PrintTable();
	int num,			//номер удал€емой записи
		n;				//позици€ удал€емого элемента
	cout << "¬ведите номер удал€емой записи от 1 до " << value << "( 0 - ƒл€ выхода): ";
	cin >> num;
	while (check_input(9) != 1 || num < 0 || num > value) {
		if (num < 1) {
			cout << "¬веден несуществующий номер записи! ѕовторите попытку!\n";
		}
		else if (num > value) {
			cout << "Ќомер записи превышает их количество! ѕовторите попытку!\n";
		}
		cin.clear();
		cin.ignore(100000000, '\n');
		cin >> num;
	}
	if (num != 0) {
		n = num - 1;
		_hotel *buff = head;
		if (n == 0) {
			if (value == 1) {
				head = tail = NULL;
				free(buff);
				value--;		//уменьшение размера
			}
			else {
				head = head->next;
				head->prev = NULL;
				free(buff);
				value--;		//уменьшение размера
			}
		}
		else if (n == value - 1) {
			buff = tail;
			tail = tail->prev;
			tail->next = NULL;
			free(buff);
			value--;		//уменьшение размера
		}
		else {
			_hotel *buff = head;
			int score = 0;
			do
			{
				if (n == score) {
					_hotel *tempPrev = buff->prev,
						*tempNext = buff->next;
					tempPrev->next = tempNext;
					tempNext->prev = tempPrev;
					free(buff);
					value--;		//уменьшение размера
					break;
				}
				else {
					buff = buff->next,
						score++;
				}
			} while (buff != NULL);

		}
	}
}