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


using namespace std;

int check_input(int type) {		//функция проверки ввода
	if (type == 1) {
		if (num > 0 && num <= 500 && cin.good()) {
			return 1;
		}
		else {
			return -1;
		}
	}
	else if (type == 2) {
		int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (arr[2] >= 1950) {
			if (arr[2] % 4 == 0) {
				days[2] = 29;
			}
			if (arr[1] < 1 || arr[1] > 12) {
				return -1;
			}
			if (arr[0] < 1 || arr[0] > days[arr[1]]) {
				return -1;
			}
			if (ch != '/') {
				return -1;
			}
			if (ch2 != '/') {
				return -1;
			}
		}
		else {
			return -1;
		}
		return 1;
	}
	else if (type == 3) {
		if (strlen(str) > 29 || strlen(str) == 0) {
			return -1;
		}
		return 1;
	}
	else if (type == 4) {
		if (num < 1 || num > 5) {
			return -1;
		}
		return 1;
	}
	else if (type == 5) {
		if (num > 0 && num <= 1000 && cin.good()) {
			return 1;
		}
		else {
			return -1;
		}
	}
	else if (type == 6) {
		if (strlen(str) > 11 || strlen(str) == 0) {
			return -1;
		}
		return 1;
	}
	else if (type == 7) {
		if (num > 0 && num <= 3 && cin.good()) {
			return 1;
		}
		else {

			return -1;
		}
	}
	else if (type == 8) {
		if (strlen(str) > 17 || strlen(str) == 0) {
			return -1;
		}
		return 1;
	}
	else if (type == 9) {
		if (cin.good()) {
			return 1;
		}
		else {
			return -1;
		}
	}
	else if (type == 10) {
		int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (arr2[2] >= 1950) {
			if (arr2[2] % 4 == 0) {
				days[2] = 29;
			}
			if (arr2[1] < 1 || arr2[1] > 12) {
				return -1;
			}
			if (arr2[0] < 1 || arr2[0] > days[arr2[1]]) {
				return -1;
			}
			if (ch != '/') {
				return -1;
			}
			if (ch2 != '/') {
				return -1;
			}
		}
		else {
			return -1;
		}
		return 1;
	}
	else if (type == 11) {
		if (strlen(str) > 26 || strlen(str) == 0) {
			return -1;
		}
		else {
			return 1;
		}
	}
	else if (type == 12) {
		for (int i = 0; i < strlen(str); i++) {
			if (str[i] != ' ') {
				return 1;
			}
		}
		return -1;
	}
}