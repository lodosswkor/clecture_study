#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main01(void) {

	FILE* stream; 
	int file_state; 

	stream = fopen("data.txt", "r"); 
	if (stream == NULL) {
		printf("File Open Error!!");
		return; 
	}

	file_state = fclose(stream);
	if (file_state == EOF) {  // success 0 , fail -1 (EOF)
		printf("File Close Error");
		return;
	}

	return 0;
}