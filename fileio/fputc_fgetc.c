#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main03(void) {
	
	FILE* p = fopen("test.txt", "w");
	fputc('a', p);
	fputc('b', p);
	fputc('c', p);
	fputc('d', p);
	fputc('e', p);
	fputc('f', p);
	fputc('g', p);

	//fputc('a', stdout);

	
	fclose(p);
	return 0;
}