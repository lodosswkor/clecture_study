#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//-- line 단위 읽고 쓰기 

int main04(void) {

	FILE* p = fopen("text.txt", "r");
	char buf[100];

	if (p == NULL) {
		printf("error!");
		return;
	}

	//fgets(buf, sizeof(buf), stdin);
	//fputs(buf, p);


	//fgets(buf, sizeof(buf), p);
	//printf("%s", buf);

	char* pStr;

	while (!feof(p)) {
		pStr = fgets(buf, sizeof(buf), p);
		//printf("%s", buf);
		printf("%s", pStr);
	}

	fclose(p);
	return 0;
}