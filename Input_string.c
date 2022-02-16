int Input_string(char* result, int str_size, int kor, int eng, int num, int sign, int space) {
	CONSOLE_SCREEN_BUFFER_INFO CUR_INFO;
	COORD Pos;
	int index = 0;
	int last_jump = 0;
	int delete_index = 0;
	char input_char;
	while (1) {
		input_char = _getch();
		switch (input_char) {
		case 13:
			printf("\n");
			return 1;
		case 8:
			if (index == 0)
				break;
			delete_index = 0;
			last_jump = 0;
			while (result[delete_index] != '\0') {
				if (result[delete_index] & 0x80) {
					last_jump = 2;
					delete_index += last_jump;
				}
				else {
					last_jump = 1;
					delete_index += last_jump;
				}
			}
			delete_index -= last_jump;
			result[delete_index] = '\0';
			GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CUR_INFO);
			if (last_jump == 2) {
				Pos.X = (CUR_INFO.dwCursorPosition.X) - 2; Pos.Y = CUR_INFO.dwCursorPosition.Y;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
				printf("  ");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
				index -= 2;
			}
			else {
				Pos.X = (CUR_INFO.dwCursorPosition.X) - 1; Pos.Y = CUR_INFO.dwCursorPosition.Y;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
				printf(" ");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
				index--;
			}
			break;
		case 27:
			result[0] = '\0';
			return 0;

		default:
			if (index == str_size)
				break;

			if (space && input_char == 32) {
				result[index++] = input_char;
				result[index] = '\0';
				printf("%c", result[index - 1]);
				break;
			}

			if (kor && (input_char & 0x80)) {
				if (index < (str_size - 2)) {
					result[index++] = input_char;
					input_char = _getch();
					result[index++] = input_char;
					result[index] = '\0';
					printf("%c%c", result[index - 2], result[index - 1]);
				}
				else {
					_getch();
				}
				break;
			}

			if (eng && ((input_char > 64 && input_char < 91) || (input_char > 96 && input_char < 123))) {
				result[index++] = input_char;
				result[index] = '\0';
				printf("%c", result[index - 1]);
				break;
			}

			if (num && (input_char > 47 && input_char < 58)) {
				result[index++] = input_char;
				result[index] = '\0';
				printf("%c", result[index - 1]);
				break;
			}

			if (sign && ((input_char > 32 && input_char < 48) || (input_char > 57 && input_char < 65) || (input_char > 90 && input_char < 97) || (input_char > 122 && input_char < 127))) {
				result[index++] = input_char;
				result[index] = '\0';
				printf("%c", result[index - 1]);
				break;
			}

		}
	}
}
