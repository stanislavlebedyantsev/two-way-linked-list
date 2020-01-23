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

void search() {			//������� ������ ������
	do
	{
		system("cls");
		_hotel *buff = head;
		int score = 0;
		int num_field = 0;
		cout << "�� ����� � ���� ������! �������� �� ������ ���� ������ ������:\n";
		cout << "1 - ����� � �����\n";
		cout << "2 - ���� ������������\n";
		cout << "3 - ������� ���������� \n";
		cout << "4 - ������ ������ \n";
		cout << "5 - ���� \n";
		cout << "6 - ��� ������ \n";
		cout << "7 - ���������� ������ \n";
		cout << "8 - ��� ������������ \n";
		cout << "0 - ����� �� ������\n";
		cin >> num_field;
		if (cin.good() && num_field != 0) {
			cin.clear();
			cin.ignore(100000000, '\n');
			switch (num_field)
			{
			case 1: {
				num = 0;
				cout << "������� ����� ������� � �����(������ 0 � �� ������ 500): ";
				cin >> num;
				while (check_input(1) != 1) {
					cout << "�������� ����! ��������� �������: ";
					cin.clear();
					cin.ignore(100000000, '\n');
					cin >> num;
				}

				break;
			}
			case 2: {
				arr[0] = 0, arr[1] = 0, arr[2] = 0;
				cout << "������� ���� � ������� dd/mm/yyyy: ";
				cin >> arr[0] >> ch >> arr[1] >> ch2 >> arr[2];
				while (check_input(2) != 1 || check_input(12) != 1) {
					cout << "�������� ����! ��������� �������: ";
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
				cout << "������� ������� ����������(�� ��������� 29 ��������): ";
				gets_s(str);
				while (check_input(3) != 1) {
					cout << "�������� ����! ��������� �������: ";
					fflush(stdin);
					gets_s(str);
				}
				num = 0;
				break;
			}
			case 4: {
				num = 0;
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
					strcpy(str, "��������");
					break;
				}
				case 2: {
					strcpy(str, "�����");
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
				cout << "������� ���� ������(������ 0 � �� ����� 1000): ";
				cin >> num;
				while (check_input(5) != 1) {
					cout << "�������� ����! ��������� �������: ";
					cin.clear();
					cin.ignore(100000000, '\n');
					cin >> num;
				}
				break;
			}
			case 6: {
				fflush(stdin);
				getchar();
				cout << "������� ��� ������(�� ��������� 11 ��������): ";
				gets_s(str);
				while (check_input(6) != 1 || check_input(12) != 1) {
					cout << "�������� ����! ��������� �������: ";
					fflush(stdin);
					gets_s(str);
				}
				num = 0;
				break;
			}
			case 7: {
				num = 0;
				cout << "������� ���������� ������(������ 0 � �� ����� 3) : ";
				cin >> num;
				while (check_input(7) != 1) {
					cout << "�������� ����! ��������� �������: ";
					cin.clear();
					cin.ignore(100000000, '\n');
					cin >> num;
				}
				break;
			}
			case 8: {
				fflush(stdin);
				getchar();
				cout << "������� ��� ������������(�� ��������� 17 ��������): ";
				gets_s(str);
				while (check_input(8) != 1 || check_input(12) != 1) {
					cout << "�������� ����! ��������� �������: ";
					fflush(stdin);
					gets_s(str);
				}
				num = 0;
				break;
			}
			default:
				cout << "�������� �������������� ����! ��������� �������\n";
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
					cout << "������ �� ���� �������!\n";
					system("pause");
				}
				else {
					cout << "\n����� �������!\n";
					system("pause");
				}
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