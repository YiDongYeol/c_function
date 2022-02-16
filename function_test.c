void main() {
	char result[21];
	char menu[5][MENU_LENGTH] = { "aaaaa","bbbbb","Ccccc","Ddddd","eeeee" };
	char pre_input[] = "\0";
	char aft_input[] = "\n==========================\n메뉴를 선택해 주세요\n";
	char date[DATE_LENGTH];

	Input_string(result, 20, 1, 1, 1, 1, 1);			//문자열 입력 함수
	printf("%s\n", result);						//문자열 저장공간 result
									//마지막 \0(NULL)을 제외한 공간 20
									//한글입력 불가, 공백 불가, 나머지 가능 모드

	//Menu_select("\0", menu, aft_input, 5);			//메뉴 선택 함수
									//pre, aft는 직접 입력해도 되고 따로 문자열을 만들어서 입력도 가능
									//현재 pre는 "\0"로 없음을 직접 입력
									//현재 aft는 aft_input으로 문자열을 만들어 입력
									//menu는 메뉴가 저장된 이차원배열
									//5는 메뉴의 개수						

	//Input_date(date, 1);						//직접날짜 입력모드
	//printf("%s\n", date);

	//Input_date(date, 2);						//현재날짜 자동입력모드
	//printf("%s\n", date);
}
