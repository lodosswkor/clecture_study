//--- MS C에서만 사용 ---------------
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 
//--------------------------------
#include <stdio.h>


int main02()
{
    FILE* stream;
    int file_state;
    int input = 0;

    stream = fopen("data2.txt", "w");
    if (stream == NULL)
        puts("파일 열기 에러");

    puts("데이터를 입력하시오.");

    while ((input = fgetc(stdin)) != EOF)
    {
        if (input == 10) break; // LF
        fputc(input, stream);
    }

    file_state = fclose(stream);
    if (file_state == EOF)
        puts("파일 닫기 에러");

    return 0;
}