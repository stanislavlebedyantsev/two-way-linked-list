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
#include "filework.h"
#include "check_input.h"
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


void FileReadBIN();											//������� ������ ������ �� ��������� �����
void FileWriteBIN();										//������� ������ ������ � �������� ����
void FileSaveTXT();											//������� ������ � ��������� ����
void FileRemove();											//������� �������� �����
int count_lines(const char* filename);						//������� �������� ������� � �����
int check_read_file(_hotel *p);

void FileWork() {			//������� ������ � �������
	system("cls");
	char filename;
	int num_field;
	cout << "������� ��������, ������� ������ ��������� � ������!\n";
	cout << "1 - ��������� ������ �� ������������� ��������� �����\n";
	cout << "2 - �������� ������ � �������� ����\n";
	cout << "3 - ��������� ������ ���� � ��������� ����\n";
	cout << "4 - �������� ����� �� ��������\n";
	cout << "0 - ����� � ������� ����\n";
	cin >> num_field;
	while (check_input(9) != 1 || num_field > 4 || num_field < 0) {
		cout << "������ �������� ����� ����! ��������� ������� �����!\n";
		cin.clear();
		cin.ignore(100000000, '\n');
		cin >> num_field;
	}
	switch (num_field)
	{
		case 1: {
			FileReadBIN();
			break;
		}
		case 2: {
			if (value == 0) {
				cout << "��� ������ ��� ������\n";
				system("pause");
			}
			else {
				FileWriteBIN();
			}
			break;
		}
		case 3: {
			if (value == 0) {
				cout << "��� ������ ��� ������\n";
				system("pause");
			}
			else {
				FileSaveTXT();
			}
			break;
		}
		case 4: {
			FileRemove();
			break;
		}
	}
	if (num_field != 0) {
		FileWork();
	}
}

void FileSaveTXT() {		//���������� ������ ���� � ��������� ��������
	system("cls");
	FILE *file = NULL;
	_hotel *buff = head;
	char c = '\n';
	char filename[30];
	cin.clear();
	cin.ignore(100000000, '\n');
	cout << "������� ��� ����� ��� ������! �� ����� 29 ��������!(���� ������ ������������ ����,�� ������ ����� ������� � ����� �����)(0 - ��� ������ � ����)\n";
	do {
		fflush(stdin);
		gets_s(str);
		if (check_input(11) == -1 || check_input(12) != 1) {
			cout << "������������ ����! ��������� �������!\n";
			fflush(stdin);
		}
	} while (check_input(11) != 1 || check_input(12) != 1);
	if (strcmp(str, "0") != 0) {
		strcpy(filename, str);
		strcat(filename, ".txt");
		file = fopen(filename, "w");
		do
		{
			fprintf(file, "%d %d/%d/%d %s %s %d %s %d %s \n", buff->num, buff->date_base.day, buff->date_base.month, buff->date_base.year, &buff->name, &buff->typepay, buff->price, &buff->numtype, buff->roomnum, &buff->bookingtype);
			buff = buff->next;
		} while (buff != NULL);
		cout << "������ � ��������� ���� ��������!\n";
		fclose(file);
		system("pause");
	}
}

void FileRemove() {			//�������� ����� �� ��������
	system("cls");
	int choise;
	char filename[30];
	cout << "1 - �������� ���������� �����\n";
	cout << "2 - �������� ��������� �����\n";
	cout << "0 - ����������� � ����\n";
	cin >> choise;
	while (check_input(9) != 1 || choise > 2 || choise < 0) {
		cout << "������ �������� ����� ����. ��������� �������!\n";
		cin.clear();
		cin.ignore(100000000, '\n');
		cin >> choise;
	}
	system("cls");
	cin.clear();
	cin.ignore(100000000, '\n');
	cout << "������� �������� �����. �� ����� 29 ��������: ";
	do {
		fflush(stdin);
		gets_s(str);
		if (check_input(11) == -1 || check_input(12) != 1) {
			cout << "������������ ����! ��������� �������!\n";
			fflush(stdin);
		}
	} while (check_input(11) != 1 || check_input(12) != 1);
	switch (choise)
	{
		case 1: {
			strcpy(filename, str);
			strcat(filename, ".txt");
			if (remove(filename)) {
				cout << "��� ������ �����\n";
				system("pause");
				break;
			}
			else {
				cout << "���� ������� ������\n";
				system("pause");
				break;
			}
		}
		case 2: {
			strcpy(filename, str);
			strcat(filename, ".bin");
			if (remove(filename)) {
				cout << "��� ������ �����\n";
				system("pause");
				break;
			}
			else {
				cout << "���� ������� ������\n";
				system("pause");
				break;
			}
		}
		case 0: {
			break;
		}
	}
}

void FileWriteBIN() {			//������ � �������� ����
	system("cls");
	int i = 0, count_size;
	FILE *file = NULL;
	_hotel *buff = head;
	char filename[30];
	cin.clear();
	cin.ignore(100000000, '\n');
	cout << "������� ��� ����� ��� ������! �� ����� 29 ��������(���� ������ ������������ ����,�� ������ ����� ������� � ����� �����)(0 - ��� ������ � ����)\n";
	do {
		fflush(stdin);
		gets_s(str);
		if (check_input(11) == -1 || check_input(12) != 1) {
			cout << "������������ ����! ��������� �������!\n";
			fflush(stdin);
		}
	} while (check_input(11) != 1 || check_input(12) != 1);
	if (strcmp(str, "0") != 0) {
		strcpy(filename, str);
		strcat(filename, ".bin");
		file = fopen(filename, "ab");
		count_size = count_lines(filename);
		if (count_size != 0) {
			fprintf(file, "\r\n");
		}
		do
		{
			fprintf(file, "%d %d/%d/%d %s %s %d %s %d %s", buff->num, buff->date_base.day, buff->date_base.month, buff->date_base.year, &buff->name, &buff->typepay, buff->price, &buff->numtype, buff->roomnum, &buff->bookingtype);
			i++;
			if (i != value) {
				fprintf(file, "\r\n");
			}
			buff = buff->next;
		} while (buff != NULL);
		fclose(file);
		cout << "������ � �������� ���� ��������!\n";
		system("pause");
	}
}


void FileReadBIN() {		//���������� � ��������� �����
	system("cls");
	FILE *file = NULL;
	char filename[30];
	int count_size;
	cin.clear();
	cin.ignore(100000000, '\n');
	cout << "������� ��� ����� ��� ����������! �� ����� 29 ��������(0 - ������ � ����)\n";
	do {
		fflush(stdin);
		gets_s(str);
		if (check_input(11) == -1 || check_input(12) != 1) {
			cout << "�������� ����� �������� ��� ����� ����� ��� ������� ������ ������! ��������� �������!\n";
			fflush(stdin);
		}
	} while (check_input(11) != 1 || check_input(12) != 1);
	if (strcmp(str, "0") != 0) {
		strcpy(filename, str);
		strcat(filename, ".bin");
		if (fopen(filename, "rb") == NULL) {
			cout << "���� �� ������� �������, �������� �� ������������!\n";
		}
		else if (fopen(filename, "rb") != NULL) {
			file = fopen(filename, "rb");
			count_size = count_lines(filename);
			while (!feof(file)) {
				_hotel *p = (_hotel*)malloc(sizeof(_hotel));
				fscanf(file, "%d %d/%d/%d %s %s %d %s %d %s", &p->num, &p->date_base.day, &p->date_base.month, &p->date_base.year, &p->name, &p->typepay, &p->price, &p->numtype, &p->roomnum, &p->bookingtype);
				if (check_read_file(p) == 1 || value == 0) {
					add_last(p);
					value++;
				}
				else {
					cout << "����: " << p->num << " " << p->date_base.day << "/" << p->date_base.month << "/" << p->date_base.year << " ";
					cout << p->name << " " << p->typepay << " " << p->price << " " << p->numtype << " " << p->roomnum << " " << p->bookingtype << " ";
					cout << "\n��� ����������!\n";
				}
			}
			fclose(file);
			cout << "������ �� ����� ���������!\n";
			fflush(stdin);
		}
		system("pause");
	}
}


int count_lines(const char* filename) {		//������� ���������� ������� � �������� �����
	FILE* fp;
	int cnt = 0;
	if ((fp = fopen(filename, "rb")) == NULL)
		return 0;
	while (!feof(fp) && !ferror(fp)) {
		fscanf(fp, "%*[^\n]%*c");			//����� ��������� �� ��������� ������
		cnt++;
	}
	if (ferror(fp))
		printf("������!\n");
	fclose(fp);
	return cnt;
}

int check_read_file(_hotel *p) {
	_hotel *buff = head;
	for (int i = 0; i < value; i++) {
		if (strcmp(p->bookingtype, buff->bookingtype) == 0 && p->date_base.day == buff->date_base.day && p->date_base.year == buff->date_base.year
			&& p->date_base.month == buff->date_base.month && strcmp(p->name, buff->name) == 0 && p->num == buff->num && strcmp(p->numtype, buff->numtype) == 0
			&& p->price == buff->price && p->roomnum == buff->roomnum && strcmp(p->typepay, buff->typepay) == 0) {
			return -1;
		}
		else if (value == i + 1) {
			return 1;
		}
		buff = buff->next;
	}
}
