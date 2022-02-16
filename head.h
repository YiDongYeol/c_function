#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define MENU_LENGTH 21
#define DATE_LENGTH 11
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
int Input_string(char* result, int str_size, int kor, int eng, int num, int sign, int space);
int Menu_select(char* pre_input, char menu[][MENU_LENGTH], char* aft_input, int menu_count);
int Input_date(char result[DATE_LENGTH], int mode);
