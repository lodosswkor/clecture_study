#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {

	FILE* stream2 = fopen("student2.txt", "w");

	const int std_count = 1; // 학생 수 상수 (3명)  
	char* name_a[3];
	char* std_no_a[3];
	char* major_a[3];

	// scanf 의 경우는, 직접 제공된 포인터변수에 값을 입력하는 함수, 
	// 제공한 포인터변수의 경우에는, 그 값의 크기는 존재해야한다. 

	char temp[100]; // scanf를 위한 100bytes 의 공간을 미리 확보 

	for (int i = 0; i < std_count; i++) {

		puts("학생이름을 입력해 주세요 > ");
		scanf("%s", temp);
		name_a[i] = _strdup(temp); // str dupplication 

		puts("학번을 입력해 주세요 > ");
		scanf("%s", temp);
		std_no_a[i] = _strdup(temp); // str dupplication 

		puts("전공을 입력해 주세요 > ");
		scanf("%s", temp);
		major_a[i] = _strdup(temp); // str dupplication 

		fprintf(stream2, "학번 : %s, 이름 : %s, 전공 %s\n", name_a[i], std_no_a[i], major_a[i]); // file output (파일로 출력) 

		// file IO -> I : Input, O : Output 
		// printf() 인풋? 아웃풋? -> 화면에 '출력' - 아웃풋 
		// scanf() 인풋? 아웃풋? -> 사용자의 키보드에서 '입력' - 인풋  

	}


	fclose(stream2);
	
	FILE* stream3 = fopen("student2.txt", "r");
	int i = 0; 
	while (!ifeof(stream3)) {
		fscanf(stream3, "%s, %s, %s", name_a[i], std_no_a[i], major_a[i]);
		printf("%s %s %s\n", name_a[i], std_no_a[i], major_a[i]);
		i++;
	}
	fclose(stream3);
	return 0;
}