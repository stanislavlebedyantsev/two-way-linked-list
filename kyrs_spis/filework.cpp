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


void FileReadBIN();											//функция чтения данных из бинарного файла
void FileWriteBIN();										//функция записи данных в бинарный файл
void FileSaveTXT();											//функция записи в текстовый файл
void FileRemove();											//функция удаления файла
int count_lines(const char* filename);						//функция подсчёта записей в файле
int check_read_file(_hotel *p);

void FileWork() {			//функция работы с файлами
	system("cls");
	char filename;
	int num_field;
	cout << "Введите действие, которое хотите совершить с файлом!\n";
	cout << "1 - Загрузить данные из существующего бинарного файла\n";
	cout << "2 - Записать данные в бинарный файл\n";
	cout << "3 - Сохранить данные базы в текстовый файл\n";
	cout << "4 - Удаление файла по названию\n";
	cout << "0 - Выход в главное меню\n";
	cin >> num_field;
	while (check_input(9) != 1 || num_field > 4 || num_field < 0) {
		cout << "Выбран неверный пункт меню! Повторите попытку ввода!\n";
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
				cout << "Нет данных для записи\n";
				system("pause");
			}
			else {
				FileWriteBIN();
			}
			break;
		}
		case 3: {
			if (value == 0) {
				cout << "Нет данных для записи\n";
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

void FileSaveTXT() {		//сохранения данных базы в текстовый документ
	system("cls");
	FILE *file = NULL;
	_hotel *buff = head;
	char c = '\n';
	char filename[30];
	cin.clear();
	cin.ignore(100000000, '\n');
	cout << "Введите имя файла для записи! Не более 29 символов!(Если введен существующий файл,то запись будет вестись в конец файла)(0 - Для выхода в меню)\n";
	do {
		fflush(stdin);
		gets_s(str);
		if (check_input(11) == -1 || check_input(12) != 1) {
			cout << "Некорректный ввод! Повторите попытку!\n";
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
		cout << "Запись в текстовый файл окончена!\n";
		fclose(file);
		system("pause");
	}
}

void FileRemove() {			//удаление файла по названию
	system("cls");
	int choise;
	char filename[30];
	cout << "1 - Удаление текстового файла\n";
	cout << "2 - Удаление бинарного файла\n";
	cout << "0 - Возвращение в меню\n";
	cin >> choise;
	while (check_input(9) != 1 || choise > 2 || choise < 0) {
		cout << "Введен неверный пункт меню. Повторите попытку!\n";
		cin.clear();
		cin.ignore(100000000, '\n');
		cin >> choise;
	}
	system("cls");
	cin.clear();
	cin.ignore(100000000, '\n');
	cout << "Введите название файла. Не более 29 символов: ";
	do {
		fflush(stdin);
		gets_s(str);
		if (check_input(11) == -1 || check_input(12) != 1) {
			cout << "Некорректный ввод! Повторите попытку!\n";
			fflush(stdin);
		}
	} while (check_input(11) != 1 || check_input(12) != 1);
	switch (choise)
	{
		case 1: {
			strcpy(filename, str);
			strcat(filename, ".txt");
			if (remove(filename)) {
				cout << "Нет такого файла\n";
				system("pause");
				break;
			}
			else {
				cout << "Файл успешно удален\n";
				system("pause");
				break;
			}
		}
		case 2: {
			strcpy(filename, str);
			strcat(filename, ".bin");
			if (remove(filename)) {
				cout << "Нет такого файла\n";
				system("pause");
				break;
			}
			else {
				cout << "Файл успешно удален\n";
				system("pause");
				break;
			}
		}
		case 0: {
			break;
		}
	}
}

void FileWriteBIN() {			//запись в бинарный файл
	system("cls");
	int i = 0, count_size;
	FILE *file = NULL;
	_hotel *buff = head;
	char filename[30];
	cin.clear();
	cin.ignore(100000000, '\n');
	cout << "Введите имя файла для записи! Не более 29 символов(Если введен существующий файл,то запись будет вестись в конец файла)(0 - Для выхода в меню)\n";
	do {
		fflush(stdin);
		gets_s(str);
		if (check_input(11) == -1 || check_input(12) != 1) {
			cout << "Некорректный ввод! Повторите попытку!\n";
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
		cout << "Запись в бинарный файл окончена!\n";
		system("pause");
	}
}


void FileReadBIN() {		//считывание с бинарного файла
	system("cls");
	FILE *file = NULL;
	char filename[30];
	int count_size;
	cin.clear();
	cin.ignore(100000000, '\n');
	cout << "Введите имя файла для считывания! Не более 29 символов(0 - Выхода в меню)\n";
	do {
		fflush(stdin);
		gets_s(str);
		if (check_input(11) == -1 || check_input(12) != 1) {
			cout << "Превышен лимит символов для имени файла или введена пустая строка! Повторите попытку!\n";
			fflush(stdin);
		}
	} while (check_input(11) != 1 || check_input(12) != 1);
	if (strcmp(str, "0") != 0) {
		strcpy(filename, str);
		strcat(filename, ".bin");
		if (fopen(filename, "rb") == NULL) {
			cout << "Файл не удалось открыть, возможно он несуществует!\n";
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
					cout << "Поле: " << p->num << " " << p->date_base.day << "/" << p->date_base.month << "/" << p->date_base.year << " ";
					cout << p->name << " " << p->typepay << " " << p->price << " " << p->numtype << " " << p->roomnum << " " << p->bookingtype << " ";
					cout << "\nУже существует!\n";
				}
			}
			fclose(file);
			cout << "Чтение из файла закончено!\n";
			fflush(stdin);
		}
		system("pause");
	}
}


int count_lines(const char* filename) {		//подсчёт количества записей в бинарном файле
	FILE* fp;
	int cnt = 0;
	if ((fp = fopen(filename, "rb")) == NULL)
		return 0;
	while (!feof(fp) && !ferror(fp)) {
		fscanf(fp, "%*[^\n]%*c");			//поиск переходов на следующую строку
		cnt++;
	}
	if (ferror(fp))
		printf("Ошибка!\n");
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
