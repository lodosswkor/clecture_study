//--- MS C������ ��� ---------------
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
        puts("���� ���� ����");

    puts("�����͸� �Է��Ͻÿ�.");

    while ((input = fgetc(stdin)) != EOF)
    {
        //printf("%d\n", input);
        if (input == 10) break; // LF
        fputc(input, stream);
    }

    file_state = fclose(stream);
    if (file_state == EOF)
        puts("���� �ݱ� ����");

    return 0;
}