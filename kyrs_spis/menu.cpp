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

void ClearMem();											//������� ������ ����� �������

void menu() {	//���� �����
	system("cls");
	cout << "1 - ���� ����� ���������\n";
	cout << "2 - ����� ���������\n";
	cout << "3 - �������� ��������\n";
	cout << "4 - �������������� ��������\n";
	cout << "5 - ����� ��������\n";
	cout << "6 - ���������� ���������\n";
	cout << "7 - ���������� ��������� �� �������\n";
	cout << "0 - ���� ����� � �������\n";
	cout << "ESC ��� ������...\n";
	switch (_getch()) {
		case 27: {
			if (value != 0) {
				cout << "������ �����!\n";
				ClearMem();
				exit(0);
			}
			else {
				cout << "������ �����!\n";
				exit(0);
			}

		}
		case 49: {
			do
			{
				system("cls");
				cout << "1 - ���� � ����� ������\n";
				cout << "2 - ���� � ������ ������\n";
				cout << "3 - ���� � ��������� ������� ������\n";
				cout << "0 - ����� � ����\n";
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
					cout << "��� ���������� ������ ����! ��������� �������!\n";
					system("pause");
				}
			} while (1);
			break;
		}
		case 50: {
			system("cls");
			if (value == 0) {
				cout << "��� �������!\n";
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
				cout << "��� �������!\n";
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
				cout << "��� �������!\n";
				system("pause");
			}
			else {
				system("cls");
				int pos;
				PrintTable();
				cout << "������� ����� �������� ��� ��������������( 0 - ����� � ����): ";
				cin >> pos;
				while (check_input(9) != 1 || pos > value || pos < 0) {
					cout << "����� �������� ������ ������� ������! ��������� �������: ";
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
				cout << "��� �������!\n";
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
				cout << "��� �������!\n";
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
				cout << "��� �������!\n";
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
			cout << "\n��� ���������� ������ ����! ��������� �������!\n";
			system("pause");
			break;
		}
	}
	menu();
}

void ClearMem() {		//������� ������ ����� �������
	do {
		_hotel *buff = head;
		head = head->next;
		free(buff);
	} while (head != NULL);
}