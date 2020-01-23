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
	int num;												//�����
	struct date
	{
		int day;
		int month;
		int year;
	}date_base;												//���� �����
	char name[30];											//������� ����������
	char typepay[15];										//������ ������
	int price;												//����
	char numtype[12];										//��� ������
	int roomnum;											//���������� ������
	char bookingtype[18];									//��� �����
	struct _hotel *next;									//��������� �� ��������� �������
	struct _hotel *prev;									//��������� �� ���������� �������

};

extern _hotel *head;										//��������� �� ������ ������
extern _hotel *tail;										//��������� �� ����� ������

void DelElem() {		//�������� �������� �� ������
	system("cls");
	PrintTable();
	int num,			//����� ��������� ������
		n;				//������� ���������� ��������
	cout << "������� ����� ��������� ������ �� 1 �� " << value << "( 0 - ��� ������): ";
	cin >> num;
	while (check_input(9) != 1 || num < 0 || num > value) {
		if (num < 1) {
			cout << "������ �������������� ����� ������! ��������� �������!\n";
		}
		else if (num > value) {
			cout << "����� ������ ��������� �� ����������! ��������� �������!\n";
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
				value--;		//���������� �������
			}
			else {
				head = head->next;
				head->prev = NULL;
				free(buff);
				value--;		//���������� �������
			}
		}
		else if (n == value - 1) {
			buff = tail;
			tail = tail->prev;
			tail->next = NULL;
			free(buff);
			value--;		//���������� �������
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
					value--;		//���������� �������
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