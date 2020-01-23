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
#include "edit.h"


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

void edit(int pos) {	//������� ��������������
	_hotel *buff = head;
	pos--;
	int score = 0;
	do
	{
		if (pos == score) {
			break;
		}
		else {
			buff = buff->next,
				score++;
		}
	} while (buff != NULL);

	int num_field = 0;
	do {
		system("cls");
		cout << "| � | ����� � ����� | ���� ������������ |       ������� ����������     | ������ ������ | ���� ������ | ��� ������ | ���������� ������ | ��� ������������ |\n";
		cout << "|" << setw(3) << pos + 1;
		cout << '|' << setw(15) << buff->num << '|';
		if (buff->date_base.day < 10) {
			cout << setw(11) << '0' << buff->date_base.day << '/';
		}
		else {
			cout << setw(11) << buff->date_base.day << '/';
		}
		if (buff->date_base.month < 10) {
			cout << '0' << buff->date_base.month;
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
		cout << "�������� ����: \n";
		cout << "1 - ����� � �����\n";
		cout << "2 - ���� ������������\n";
		cout << "3 - ������� ���������� \n";
		cout << "4 - ������ ������ \n";
		cout << "5 - ���� \n";
		cout << "6 - ��� ������ \n";
		cout << "7 - ���������� ������ \n";
		cout << "8 - ��� ������������ \n";
		cout << "0 - ����� �� ��������������\n";
		cin >> num_field;
		if (cin.good() && num_field != 0) {
			switch (num_field)
			{
			case 1: {
				num = 0;
				cout << "������� ����� ����� ������� � �����(������ 0 � �� ������ 500): ";
				cin >> num;
				while (check_input(1) != 1) {
					cout << "�������� ����! ��������� �������: ";
					cin.clear();
					cin.ignore(100000000, '\n');
					cin >> num;
				}
				buff->num = num;
				break;
			}
			case 2: {
				cin.clear();
				cin.ignore(100000000, '\n');
				arr[0] = 0, arr[1] = 0, arr[2] = 0;
				cout << "������� ����� ���� � ������� dd/mm/yyyy: ";
				cin >> arr[0] >> ch >> arr[1] >> ch2 >> arr[2];
				while (check_input(2) != 1) {
					cout << "�������� ����! ��������� �������: ";
					cin.clear();
					cin.ignore(100000000, '\n');
					cin >> arr[0] >> ch >> arr[1] >> ch2 >> arr[2];
				}
				buff->date_base.day = arr[0], buff->date_base.month = arr[1], buff->date_base.year = arr[2];
				break;
			}
			case 3: {
				fflush(stdin);
				cin.clear();
				cin.ignore(100000000, '\n');
				cout << "������� ����� ������� ����������(�� ��������� 29 ��������): ";
				gets_s(str);
				while (check_input(3) != 1 || check_input(12) != 1) {
					cout << "�������� ����! ��������� �������: ";
					fflush(stdin);
					gets_s(str);
				}
				strcpy(buff->name, str);
				break;
			}
			case 4: {
				num = 0;
				cin.clear();
				cin.ignore(100000000, '\n');
				cout << "�������� �� ������������ ��������� ����� ������ ������\n" << "1 - ��������\n2 - �����\n3 - ApplePay\n4 - SamsungPay\n5 - GooglePay\n";
				cin >> num;
				while (check_input(4) != 1) {
					cout << "�������� ����! ��������� �������: ";
					cin.clear();
					cin.ignore(100000000, '\n');
					cin >> num;
				}
				switch (num) {
				case 1: {
					strcpy(buff->typepay, "��������");
					break;
				}
				case 2: {
					strcpy(buff->typepay, "�����");
					break;
				}
				case 3: {
					strcpy(buff->typepay, "ApplePay");
					break;
				}
				case 4: {
					strcpy(buff->typepay, "SamsungPay");
					break;
				}
				case 5: {
					strcpy(buff->typepay, "GooglePay");
					break;
				}
				}
				break;
			}
			case 5: {
				num = 0;
				cin.clear();
				cin.ignore(100000000, '\n');
				cout << "������� ����� ���� ������(������ 0 � �� ����� 1000): ";
				cin >> num;
				while (check_input(5) != 1) {
					cout << "�������� ����! ��������� �������: ";
					cin.clear();
					cin.ignore(100000000, '\n');
					cin >> num;
				}
				buff->price = num;
				break;
			}
			case 6: {
				fflush(stdin);
				cin.clear();
				cin.ignore(100000000, '\n');
				cout << "������� ����� ��� ������(�� ��������� 11 ��������): ";
				gets_s(str);
				while (check_input(6) != 1 || check_input(12) != 1) {
					cout << "�������� ����! ��������� �������: ";
					fflush(stdin);
					gets_s(str);
				}
				strcpy(buff->numtype, str);
				break;
			}
			case 7: {
				num = 0;
				cin.clear();
				cin.ignore(100000000, '\n');
				cout << "������� ����� ���������� ������(������ 0 � �� ����� 3) : ";
				cin >> num;
				while (check_input(7) != 1) {
					cout << "�������� ����! ��������� �������: ";
					cin.clear();
					cin.ignore(100000000, '\n');
					cin >> num;
				}
				buff->roomnum = num;
				break;
			}
			case 8: {
				fflush(stdin);
				cin.clear();
				cin.ignore(100000000, '\n');
				cout << "������� ����� ��� ������������(�� ��������� 17 ��������): ";
				gets_s(str);
				while (check_input(8) != 1 || check_input(12) != 1) {
					cout << "�������� ����! ��������� �������: ";
					fflush(stdin);
					gets_s(str);
				}
				strcpy(buff->bookingtype, str);
				break;
			}
			default:
				cout << "�������� �������������� ����! ��������� �������\n";
				system("pause");
				break;
			}
		}
		else if (!cin.good()) {
			cout << "������ ����� ������ ������! ��������� �������!\n ";
			cin.clear();
			cin.ignore(100000000, '\n');
			system("pause");
		}
		else {
			break;
		}
	} while (1);
}