#define _CRT_SECURE_NO_WARNINGS 
#define _GNU_SOURCE
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

void PrintTable() {		//����� ������ � ��������� �����
	_hotel *buff = head;
	int i = 1;
	cout << "| � | ����� � ����� | ���� ������������ |       ������� ����������     | ������ ������ | ���� ������ | ��� ������ | ���������� ������ | ��� ������������ |\n";
	do {
		cout << "|" << setw(3) << i;
		cout << '|' << setw(15) << buff->num << '|';
		if (buff->date_base.day < 10) {
			cout << setw(10) << 0 << buff->date_base.day << "/";
		}
		else {
			cout << setw(11) << buff->date_base.day << "/";
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
		buff = buff->next;
		i++;
	} while (buff != NULL);
}


