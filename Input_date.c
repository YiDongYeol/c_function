int Input_date(char result[DATE_LENGTH], int mode) {
	CONSOLE_SCREEN_BUFFER_INFO CUR_INFO;
	COORD Pos;
	time_t ctime;
	struct tm* ctime_info;
	char input_char;
	int index = 0;
	switch (mode) {
	case 1:
		strcpy(result, "****/**/**");
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CUR_INFO);
		Pos.X = CUR_INFO.dwCursorPosition.X; Pos.Y = CUR_INFO.dwCursorPosition.Y;
		printf("%s", result);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
		while (1) {
			input_char = _getch();
			switch (input_char) {
			case 13:
				if (index != 10)
					break;
				printf("\n");
				return 1;
			case 27:
				strcpy(result, "****/**/**");
				return 0;
			case 8:
				if (index == 0)
					break;
				if (index == 5 || index == 8) {
					index -= 2;
					result[index] = '*';
					GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CUR_INFO);
					Pos.X = CUR_INFO.dwCursorPosition.X - 2; Pos.Y = CUR_INFO.dwCursorPosition.Y;

				}
				else {
					result[--index] = '*';
					GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CUR_INFO);
					Pos.X = CUR_INFO.dwCursorPosition.X - 1; Pos.Y = CUR_INFO.dwCursorPosition.Y;
				}
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
				printf("*");
				GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CUR_INFO);
				Pos.X = CUR_INFO.dwCursorPosition.X - 1; Pos.Y = CUR_INFO.dwCursorPosition.Y;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
				break;
			default:
				if (index == 10)
					break;
				if (input_char > 47 && input_char < 58) {
					if (index == 5 && input_char > 49)
						break;
					if (index == 6 && result[5] == 49 && input_char > 50)
						break;
					if (index == 6 && result[5] == 48 && input_char == 48)
						break;
					if (index == 8) {
						char tmp[11];
						int month;
						strcpy(tmp, result);
						strtok(tmp, "/");
						month = atoi(strtok(NULL, "/"));
						if (input_char > 51)
							break;
						if (month == 2) {
							if (input_char > 50)
								break;
						}
					}
					if (index == 9) {
						char tmp[11];
						int year;
						int month;
						strcpy(tmp, result);
						year = atoi(strtok(tmp, "/"));
						month = atoi(strtok(NULL, "/"));
						if (result[8] == 48 && input_char == 48)
							break;
						if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
							if (result[8] == 51 && input_char > 49)
								break;
						}
						else if (month == 4 || month == 6 || month == 9 || month == 11) {
							if (result[8] == 51 && input_char > 48)
								break;
						}
						else if (month == 2) {
							int leap_year = 0;
							if (year % 4 == 0) {
								if (year % 100 == 0) {
									if (year % 400 == 0) {
										leap_year = 1;
									}
								}
								else
									leap_year = 1;
							}
							if (result[8] == 50) {
								if (leap_year == 0) {
									if (input_char > 56)
										break;
								}
							}
						}
					}
					result[index++] = input_char;
					printf("%c", result[index - 1]);
					if (index == 4 || index == 7) {
						GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CUR_INFO);
						Pos.X = CUR_INFO.dwCursorPosition.X + 1; Pos.Y = CUR_INFO.dwCursorPosition.Y;
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
						index++;
					}
					break;
				}
			}
		}

	case 2:
		ctime = time(NULL);
		ctime_info = localtime(&ctime);
		sprintf(result, "%d/%02d/%02d", ctime_info->tm_year + 1900, ctime_info->tm_mon + 1, ctime_info->tm_mday);

		return -1;
	}
}
