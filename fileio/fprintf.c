//--- MS C������ ��� ---------------
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 
//--------------------------------
#include <stdio.h>


int main07(void)
{
    FILE* stream;
    char name[10];
    int kor, eng, total;

    printf("1. �̸� �Է� : ");
    fscanf(stdin, "%s", name);

    printf("2. ���� ����, ���� ���� �Է� : ");
    fscanf(stdin, "%d %d", &kor, &eng);
    total = kor + eng;

    stream = fopen("data3.txt", "w");
    if (stream != NULL)
    {
        fprintf(stream, "%s %d %d %d\n", name, kor, eng, total);
        //fprintf(stdout, "%s %d %d %d\n", name, kor, eng, total);
    }
    else
    {
        puts("���� ���� ����");
    }
    fclose(stream);

    return 0;
}