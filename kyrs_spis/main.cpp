// kyrs_spis.cpp: ���������� ����� ����� ��� ����������� ����������.
//

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
#include "menu.h"

using namespace std;

struct _hotel {
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

_hotel *head = NULL;										//��������� �� ������ ������
_hotel *tail = NULL;										//��������� �� ����� ������
int value = 0;												//���������� �������


char str[10000] = "", ch, ch2;
int num;
int arr[3], arr2[3];


int main()
{
	setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	menu();
    return 0;
}