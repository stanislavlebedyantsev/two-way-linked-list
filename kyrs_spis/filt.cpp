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
#include "print_for_filt.h"
#include "filt.h"


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

char str2[10000];

void Filt_str1(int num_field, int num_field2);
void Filt_str(int num_field);				//фильтрация строк
void Filt_int(int num2, int num_field, int num_field2, int way);		//фильтрация чисел
void Filt_date(int date1, int date2, int num_field2, int way);					//фильрация даты

void Filt_choise() {				//функция выбора метода фильтрации
	do {
		system("cls");
		int num_field = 0, num_field2 = 0, num2 = 0;
		arr[0] = 0, arr[1] = 0, arr[2] = 0;
		cout << "Выберете поле для фильтрации: \n";
		cout << "1 - Номер в отеле\n";
		cout << "2 - Дата бронирования\n";
		cout << "3 - Фамилия постояльца \n";
		cout << "4 - Способ оплаты \n";
		cout << "5 - Цена \n";
		cout << "6 - Тип номера \n";
		cout << "7 - Количество комнат \n";
		cout << "8 - Тип бронирования \n";
		cout << "0 - Выход из фильтрации\n";
		cin >> num_field;
		while (check_input(9) != 1 || num_field > 8 || num_field < 0) {
			cout << "Введено неверное значение! Повторите ввод!\n";
			cin.clear();
			cin.ignore(100000000, '\n');
			cin >> num_field;
		}
		if (num_field != 0) {
			system("cls");
			if (num_field != 3 && num_field != 4 && num_field != 6 && num_field != 8) {
				cout << "1 - Значения меньше указанного\n";
				cout << "2 - Значения больше указанного\n";
				cout << "3 - Промежуток значений\n";
				cout << "0 - Выход в меню!\n";
				cin >> num_field2;
				while (check_input(9) != 1 || num_field2 > 3 || num_field2 < 0) {
					cout << "Введено неверное значение! Повторите ввод!\n";
					cin.clear();
					cin.ignore(100000000, '\n');
					cin >> num_field2;
				}
			}
			cin.clear();
			cin.ignore(100000000, '\n');
			if (num_field == 3 || num_field == 4 || num_field == 6 || num_field == 8) {
				bool check_filt;
				cout << "1 - Значения меньше указанного\n";
				cout << "2 - Значения больше указанного\n";
				cout << "3 - Промежуток значений\n";
				cout << "4 - фильтр по маске\n";
				cout << "0 - Выход в меню!\n";
				cin >> num_field2;
				while (check_input(9) != 1 || num_field2 > 4 || num_field2 < 0) {
					cout << "Введено неверное значение! Повторите ввод!\n";
					cin.clear();
					cin.ignore(100000000, '\n');
					cin >> num_field2;
				}
				switch (num_field2) {
				case 1: {
					fflush(stdin);
					cin.clear();
					cin.ignore(100000000, '\n');
					cout << "Введите значение, меньше которого искать\n";
					gets_s(str);
					Filt_str1(num_field, num_field2);
					break;
				}
				case 2: {
					fflush(stdin);
					cin.clear();
					cin.ignore(100000000, '\n');
					cout << "Введите значение, больше которого искать\n";
					gets_s(str);
					Filt_str1(num_field, num_field2);
					break;
				}
				case 3: {
					fflush(stdin);
					cin.clear();
					cin.ignore(100000000, '\n');
					cout << "Введите минимальное значение в промежутке(A - самое минимальное)\n";
					gets_s(str);
					cout << "Введите максимальное значение в промежутке(Z - самое максимальное)\n";
					gets_s(str2);
					while (strcmp(str, str2) >= 0) {
						cout << "Неверно введенные данные, повторите попытку!\n";
						cout << "Введите минимальное значение в промежутке(A - самое минимальное)\n";
						gets_s(str);
						cout << "Введите максимальное значение в промежутке(Z - самое максимальное)\n";
						gets_s(str2);
					}
					Filt_str1(num_field, num_field2);
					break;
				}
				case 4:{
					do {
						check_filt = false;
						cin.clear();
						cin.ignore(100000000, '\n');
						switch (num_field) {
						case 3: {
							printf("Введите маску по которой будет производиться поиск. Ввод не более 29 символов!\n");
							gets_s(str);
							if (check_input(3) == -1 || check_input(12) != 1) {
								cout << "Неверный ввод. Повторите ввод!\n";
								fflush(stdin);
							}
							else check_filt = true;
							break;
						}
						case 4: {
							printf("Введите маску по которой будет производиться поиск. Ввод не более 11 символов!\n");
							gets_s(str);
							if ((strlen(str) > 11 || strlen(str) == 0 || check_input(12) != 1) && num_field == 4) {
								cout << "Неверный ввод. Повторите ввод!\n";
								fflush(stdin);
							}
							else check_filt = true;
							break;
						}
						case 6: {
							printf("Введите маску по которой будет производиться поиск. Ввод не более 11 символов!\n");
							gets_s(str);
							if ((check_input(6) != 1 || check_input(12) != 1) && num_field == 4) {
								cout << "Неверный ввод. Повторите ввод!\n";
								fflush(stdin);
							}
							else check_filt = true;
							break;
						}
						case 8: {
							printf("Введите маску по которой будет производиться поиск. Ввод не более 17 символов!\n");
							gets_s(str);
							if ((check_input(8) != 1 || check_input(12) != 1) && num_field == 4) {
								cout << "Неверный ввод. Повторите ввод!\n";
								fflush(stdin);
							}
							else check_filt = true;
							break;
						}
						}
					} while (check_filt != true);
					Filt_str(num_field);
				}
				}
				
			}
			else if (num_field == 1 || num_field == 5 || num_field == 7) {
				switch (num_field2) {
				case 1: {
					cout << "Введите значение, меньше которого искать\n";
					cin >> num;
					while (check_input(9) != 1) {
						cout << "Неверное число! Повторите ввод\n";
						cin.clear();
						cin.ignore(100000000, '\n');
						cin >> num;
					}
					Filt_int(num2, num_field, num_field2, 0);
					break;
				}
				case 2: {
					cout << "Введите значение, больше которого искать\n";
					cin >> num;
					while (check_input(9) != 1) {
						cout << "Неверное число! Повторите ввод\n";
						cin.clear();
						cin.ignore(100000000, '\n');
						cin >> num;
					}
					Filt_int(num2, num_field, num_field2, 0);
					break;
				}
				case 3: {
					int way;
					cout << "Введите первое значение в промежутке\n";
					cin >> num;
					while (check_input(9) != 1) {
						cout << "Неверное число! Повторите ввод\n";
						cin.clear();
						cin.ignore(100000000, '\n');
						cin >> num;
					}
					cout << "Введите второе значение в промежутке\n";
					cin >> num2;
					while (check_input(9) != 1) {
						cout << "Неверное число! Повторите ввод\n";
						cin.clear();
						cin.ignore(100000000, '\n');
						cin >> num2;
					}
					do {
						if (num > num2) {
							printf("Фильтрация в промежутке от %d до %d\n", num2, num);
							way = 1;
							break;
						}
						else if (num < num2) {
							printf("Фильтрация в промежутке от %d до %d\n", num, num2);
							way = 2;
							break;
						}
						else if (num == num2) {
							cout << "Значения не могут быть одинаковыми! Повторите ввод!\n";
							cout << "Введите первое значение в промежутке\n";
							cin >> num;
							while (check_input(9) != 1) {
								cout << "Неверное число! Повторите ввод\n";
								cin.clear();
								cin.ignore(100000000, '\n');
								cin >> num;
							}
							cout << "Введите второе значение в промежутке\n";
							cin >> num2;
							while (check_input(9) != 1) {
								cout << "Неверное число! Повторите ввод\n";
								cin.clear();
								cin.ignore(100000000, '\n');
								cin >> num2;
							}
						}
					} while (1);
					Filt_int(num2, num_field, num_field2, way);
					break;
				}
				}
			}


			else if(num_field == 2){
				switch (num_field2) {
					case 1: {
						int date1, date2, way;
						cout << "Введите значение, меньше которого искать в формате dd/mm/yyyy\n";
						cin >> arr[0] >> ch >> arr[1] >> ch2 >> arr[2];
						while (check_input(2) != 1) {
							cout << "Введите значение, меньше которого искать в формате dd/mm/yyyy\n";
							cout << "Введено неверное значение даты!\n";
							cin.clear();
							cin.ignore(100000000, '\n');
							cin >> arr[0] >> ch >> arr[1] >> ch2 >> arr[2];
						}
						date1 = arr[2] * 365 + arr[1] * 31 + arr[0];
						Filt_date(date1, 0, num_field2, 0);
						break;
					}
					case 2: {
						int date1, date2, way;
						cout << "Введите значение, больше которого искать в формате dd/mm/yyyy\n";
						cin >> arr[0] >> ch >> arr[1] >> ch2 >> arr[2];
						while (check_input(2) != 1) {
							cout << "Введите значение, меньше которого искать в формате dd/mm/yyyy\n";
							cout << "Введено неверное значение даты!\n";
							cin.clear();
							cin.ignore(100000000, '\n');
							cin >> arr[0] >> ch >> arr[1] >> ch2 >> arr[2];
						}
						date1 = arr[2] * 365 + arr[1] * 31 + arr[0];
						Filt_date(date1, 0, num_field2, 0);
						break;
					}
					case 3: {
						int date1, date2, way;
						cout << "Введите значение в формате dd/mm/yyyy\n";
						cin >> arr[0] >> ch >> arr[1] >> ch2 >> arr[2];
						while (check_input(2) != 1) {
							cout << "Введено неверное значение даты!\n";
							cout << "Введите значение в формате dd/mm/yyyy\n";
							cin.clear();
							cin.ignore(100000000, '\n');
							cin >> arr[0] >> ch >> arr[1] >> ch2 >> arr[2];
						}
						cout << "Введите значение в формате dd/mm/yyyy\n";
						cin >> arr2[0] >> ch >> arr2[1] >> ch2 >> arr2[2];
						while (check_input(10) != 1) {
							cout << "Введено неверное значение даты!\n";
							cout << "Введите значение в формате dd/mm/yyyy\n";
							cin.clear();
							cin.ignore(100000000, '\n');
							cin >> arr2[0] >> ch >> arr2[1] >> ch2 >> arr2[2];
						}
						do {
							date1 = arr[2] * 365 + arr[1] * 31 + arr[0];
							date2 = arr2[2] * 365 + arr2[1] * 31 + arr2[0];
							if (date1 > date2) {
								printf("Фильтрация в промежутке от %d/%d/%d до %d/%d/%d\n", arr2[0], arr2[1], arr2[2], arr[0], arr[1], arr[2]);
								Filt_date(date1, date2, num_field2, 1);
								break;
							}
							else if (date1 < date2) {
								cout << "Фильтрация будет проведена в промежутке от ";
								if (arr[0] < 10) {
									cout << "0" << arr[0];
								}
								else {
									cout << arr[0];
								}
								if (arr[1] < 10) {
									cout << "/0" << arr[1];
								}
								else {
									cout << "/" << arr[1];
								}
								cout << "/" << arr[2] << " до ";
								if (arr2[0] < 10) {
									cout << "0" << arr2[0];
								}
								else {
									cout << arr2[0];
								}
								if (arr2[1] < 10) {
									cout << "/0" << arr2[1];
								}
								else {
									cout << "/" << arr2[1];
								}
								cout << "/" << arr2[2] << endl << endl;
								Filt_date(date1, date2, num_field2, 2);
								break;
							}
							else {
								cout << "Даты не могут быть одинаковыми! Повторите ввод!\n";
								cout << "Введите значение в формате dd/mm/yyyy\n";
								cin >> arr[0] >> ch >> arr[1] >> ch2 >> arr[2];
								while (check_input(2) != 1) {
									cout << "Введено неверное значение даты!\n";
									cout << "Введите значение в формате dd/mm/yyyy\n";
									cin.clear();
									cin.ignore(100000000, '\n');
									cin >> arr[0] >> ch >> arr[1] >> ch2 >> arr[2];
								}
								cout << "Введите значение, больше которого искать в формате dd/mm/yyyy\n";
								cin >> arr2[0] >> ch >> arr2[1] >> ch2 >> arr2[2];
								while (check_input(10) != 1) {
									cout << "Введено неверное значение даты!\n";
									cout << "Введите значение, , больше которого искать в формате dd/mm/yyyy\n";
									cin.clear();
									cin.ignore(100000000, '\n');
									cin >> arr2[0] >> ch >> arr2[1] >> ch2 >> arr2[2];
								}
							}
						} while (1);
						
						break;
					}
				}
			}
		}
		else if (num_field == 0) {
			break;
		}
	}while (1);
}


void Filt_date(int date1, int date2, int num_field2, int way) {		//фильтрация даты
	_hotel *buff = head;
	int i = 0, field = 0, date;
	if (num_field2 == 1) {
		do
		{
			date = buff->date_base.day + 31 * buff->date_base.month + 365 * buff->date_base.year;
			if (date1 > date) {
				i++;
				print_for_filt(buff, i, field);
				field++;
				buff = buff->next;
			}
			else {
				buff = buff->next;
				i++;
			}
		} while (buff != NULL);
	}
	else if (num_field2 == 2) {
		do
		{
			date = buff->date_base.day + 31 * buff->date_base.month + 365 * buff->date_base.year;
			if (date1 < date) {
				i++;
				print_for_filt(buff, i, field);
				field++;
				buff = buff->next;
			}
			else {
				buff = buff->next;
				i++;
			}
		} while (buff != NULL);
	}
	else if (num_field2 == 3) {
		do
		{
			date = buff->date_base.day + 31 * buff->date_base.month + 365 * buff->date_base.year;
			if (way == 1) {
				if (date1 > date && date > date2) {
					i++;
					print_for_filt(buff, i, field);
					field++;
					buff = buff->next;
				}
				else {
					buff = buff->next;
					i++;
				}
			}
			else {
				if (date1 < date && date < date2) {
					i++;
					print_for_filt(buff, i, field);
					field++;
					buff = buff->next;
				}
				else {
					buff = buff->next;
					i++;
				}
			}
		} while (buff != NULL);
	}
	if (field == 0) {
		cout << "Ничего найдено не было\n";
	}
	system("pause");
}



void Filt_str(int num_field) {			//фильтрация строк
	_hotel *buff = head;
	int field = 0;
	int i = 0;
	char temp[30];
		do
		{
			switch (num_field) {
				case 3:{
					strcpy(temp, buff->name);
					break;
				}
				case 4: {
					strcpy(temp, buff->typepay);
					break;
				}
				case 6: {
					strcpy(temp, buff->numtype);
					break;
				}
				case 8: {
					strcpy(temp, buff->bookingtype);
					break;
				}
			}
			if ((num_field == 3 && strstr(strlwr(temp), strlwr(str)) != NULL) || (num_field == 4 && strstr(strlwr(temp), strlwr(str)) != NULL) || (num_field == 6 && strstr(strlwr(temp), strlwr(str)) != NULL) || (num_field == 6 && strstr(strlwr(temp), strlwr(str)) != NULL)) {
				i++;
				print_for_filt(buff, i, field);
				field++;
				buff = buff->next;
			}
			else {
				buff = buff->next;
				i++;
			}
		} while (buff != NULL);
	if (field == 0) {
		cout << "Ничего найдено не было\n";
	}
	system("pause");
}

void Filt_str1(int num_field, int num_field2) {			//фильтрация строк
	_hotel *buff = head;
	int i = 1;
	int kol = 0;
	char temp[30];
	if (num_field2 == 1) {
		do
		{
			switch (num_field) {
			case 3: {
				strcpy(temp, buff->name);
				break;
			}
			case 4: {
				strcpy(temp, buff->typepay);
				break;
			}
			case 6: {
				strcpy(temp, buff->numtype);
				break;
			}
			case 8: {
				strcpy(temp, buff->bookingtype);
				break;
			}
			}
			strlwr(temp);
			strlwr(str);
			strlwr(str2);
			if ((num_field == 3 && strcmp(str, temp) > 0) || (num_field == 4 && strcmp(str, temp) > 0) || (num_field == 6 && strcmp(str, temp) > 0) || (num_field == 6 && strcmp(str, temp) > 0)) {
				print_for_filt(buff, i, kol);
				buff = buff->next;
				i++;
				kol++;
			}
			else {
				buff = buff->next;
				i++;
			}
		} while (buff != NULL);
	}
	else if (num_field2 == 2) {
		do
		{
			switch (num_field) {
			case 3: {
				strcpy(temp, buff->name);
				break;
			}
			case 4: {
				strcpy(temp, buff->typepay);
				break;
			}
			case 6: {
				strcpy(temp, buff->numtype);
				break;
			}
			case 8: {
				strcpy(temp, buff->bookingtype);
				break;
			}
			}
			strlwr(temp);
			strlwr(str);
			strlwr(str2);
			if ((num_field == 3 && strcmp(str, temp) < 0) || (num_field == 4 && strcmp(str, temp) < 0) || (num_field == 6 && strcmp(str, temp) < 0) || (num_field == 8 && strcmp(str, temp) < 0)) {
				print_for_filt(buff, i, kol);
				buff = buff->next;
				i++;
				kol++;
			}
			else {
				buff = buff->next;
				i++;
			}
		} while (buff != NULL);
	}
	else if (num_field2 == 3) {
		do
		{
			switch (num_field) {
			case 3: {
				strcpy(temp, buff->name);
				break;
			}
			case 4: {
				strcpy(temp, buff->typepay);
				break;
			}
			case 6: {
				strcpy(temp, buff->numtype);
				break;
			}
			case 8: {
				strcpy(temp, buff->bookingtype);
				break;
			}
			}
			strlwr(temp);
			strlwr(str);
			strlwr(str2);
			if ((num_field == 3 && strcmp(str, temp) < 0 && strcmp(str2, temp) > 0) || (num_field == 4 && strcmp(str, temp) < 0 && strcmp(str2, temp) > 0) || (num_field == 6 && strcmp(str, temp) < 0 && strcmp(str2, temp) > 0) || (num_field == 8 && strcmp(str, temp) < 0 && strcmp(str2, temp) > 0)) {
				print_for_filt(buff, i, kol);
				buff = buff->next;
				i++;
				kol++;
			}
			else if ((num_field == 3 && (strcmp(str, temp) == 0 || strcmp(str2, temp) == 0)) || (num_field == 4 && (strcmp(str, temp) == 0 || strcmp(str2, temp) == 0)) || (num_field == 6 && (strcmp(str, temp) == 0 || strcmp(str2, temp) == 0)) || (num_field == 8 && (strcmp(str, temp) == 0 || strcmp(str2, temp) == 0))) {
				print_for_filt(buff, i, kol);
				buff = buff->next;
				i++;
				kol++;
			}
			else {
				buff = buff->next;
				i++;
			}
		} while (buff != NULL);
	}
	if (kol == 0) {
		cout << "Ничего не было найдено!\n";
	}
	system("pause");
}

void Filt_int(int num2, int num_field, int num_field2, int way) {		//фильтрация чисел
	_hotel *buff = head;
	int field = 0;
	int i = 0;
	if (num_field2 == 1) {
		do
		{
			if ((num_field == 1 && num > buff->num) || (num_field == 5 && num > buff->price) || (num_field == 7 && num > buff->roomnum)) {
				i++;
				print_for_filt(buff, i, field);
				field++;
				buff = buff->next;
			}
			else {
				buff = buff->next;
				i++;
			}
		} while (buff != NULL);
	}
	else if (num_field2 == 2) {
		do
		{
			if ((num_field == 1 && num < buff->num) || (num_field == 5 && num < buff->price) || (num_field == 7 && num < buff->roomnum)) {
				i++;
				print_for_filt(buff, i, field);
				field++;
				buff = buff->next;
			}
			else {
				buff = buff->next;
				i++;
			}
		} while (buff != NULL);
	}
	else if (num_field2 == 3) {
		do
		{
			if (way == 1) {
				if ((num_field == 1 && num > buff->num && num2 < buff->num) || (num_field == 5 && num > buff->price && num2 < buff->price) || (num_field == 7 && num > buff->roomnum && num2 < buff->roomnum)) {
					i++;
					print_for_filt(buff, i, field);
					field++;
					buff = buff->next;
				}
				else {
					buff = buff->next;
					i++;
				}
			}
			else {
				if ((num_field == 1 && num < buff->num && num2 > buff->num) || (num_field == 5 && num < buff->price && num2 > buff->price) || (num_field == 7 && num < buff->roomnum && num2 > buff->roomnum)) {
					i++;
					print_for_filt(buff, i, field);
					field++;
					buff = buff->next;
				}
				else {
					buff = buff->next;
					i++;
				}
			}
		} while (buff != NULL);
	}
	if (field == 0) {
		cout << "Ничего найдено не было\n";
	}
	system("pause");
}

