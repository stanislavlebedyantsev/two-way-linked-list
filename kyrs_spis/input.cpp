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

void add_mid(_hotel *temp);									//���������� � ��������� �������
void add_head(_hotel *temp);								//������� ���������� � ������ ������

void add_mid(_hotel *temp) {					//������� ���������� � ��������� �������
	if (head == NULL && tail == NULL) {
		cout << "������ ����, ������� ������� � ������!\n";
		add_head(temp);
		system("pause");
	}
	else {
		int pos;
		cout << "������� ����� ������ 1 � �� ������ " << value << ": ";
		cin >> pos;
		while (check_input(9) != 1 || pos <= 0 || pos > value) {
			cout << "������� �������� �������! ��������� �������!\n";
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

void add_head(_hotel *temp) {					//������� ���������� � ������ ������
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

void input(int add_type) {	//���� ��������� � ����������
	system("cls");
	bool flag = false;
	_hotel *hotel = (_hotel*)malloc(sizeof(_hotel));
	do
	{
		num = 0;
		cout << "������� ����� ������ � �����(������ 0 � �� ����� 500): ";
		cin >> num;
		if (check_input(1) == -1) {
			cout << "������� �������� ��������!\n";
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
		cout << "������� ���� � ������� dd/mm/yyyy: ";
		cin >> arr[0] >> ch >> arr[1] >> ch2 >> arr[2];
		if (check_input(2) == -1) {
			cout << "������� �������� �������� ����!\n";
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
		cout << "������� ������� ����������(�� ��������� 29 ��������): ";
		gets_s(str);
		if (check_input(3) == -1) {
			cout << "��������� ��������� ���������� �������� ��� ������� ������ ������. ��������� ����!\n";
			fflush(stdin);
		}
		else if (check_input(3) == 1 && check_input(12) == -1) {
			cout << "������ �� ����� �������� ������ �� ��������! ��������� ����!\n";
			fflush(stdin);
		}
	} while (check_input(3) != 1 || check_input(12) != 1);
	strcpy(hotel->name, str);
	do
	{
		num = 0;
		fflush(stdin);
		cout << "�������� �� ������������ ��������� ������ ������\n" << "1 - ��������\n2 - �����\n3 - ApplePay\n4 - SamsungPay\n5 - GooglePay\n";
		cin >> num;
		if (check_input(4) == -1) {
			cout << "�������� ��������! ��������� ����\n";
			cin.clear();
			cin.ignore(100000000, '\n');
		}

	} while (check_input(4) != 1);
	switch (num) {
		case 1: {
			strcpy(hotel->typepay, "��������");
			break;
		}
		case 2: {
			strcpy(hotel->typepay, "�����");
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
		cout << "������� ���� ������(������ 0 � �� ����� 1000): ";
		cin >> num;
		if (check_input(5) == -1) {
			cout << "������� �������� �������� ����!\n";
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
		cout << "������� ��� ������(�� ��������� 11 ��������): ";
		gets_s(str);
		if (check_input(6) == -1) {
			cout << "��������� ��������� ���������� �������� ��� ������� ������. ��������� ����!\n";
			fflush(stdin);
		}
		else if (check_input(6) == 1 && check_input(12) == -1) {
			cout << "������ �� ����� �������� ������ �� ��������! ��������� ����!\n";
			fflush(stdin);
		}
	} while (check_input(6) != 1 || check_input(12) != 1);
	strcpy(hotel->numtype, str);
	do
	{
		num = 0;
		cout << "������� ���������� ������(������ 0 � �� ����� 3): ";
		cin >> num;
		if (check_input(7) == -1) {
			cout << "������� �������� �������� ���������� ������!\n";
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
		cout << "������� ��� �����(�� ��������� 17 ��������): ";
		gets_s(str);
		if (check_input(8) == -1) {
			cout << "��������� ��������� ���������� �������� ��� ������� ������ ������. ��������� ����!\n";
			fflush(stdin);
		}
		else if (check_input(8) == 1 && check_input(12) == -1) {
			cout << "������ �� ����� �������� ������ �� ��������! ��������� ����!\n";
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