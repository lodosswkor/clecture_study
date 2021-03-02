//--- MS C에서만 사용 ---------------
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

    printf("1. 이름 입력 : ");
    fscanf(stdin, "%s", name);

    printf("2. 국어 점수, 영어 점수 입력 : ");
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
        puts("파일 열기 오류");
    }
    fclose(stream);

    return 0;
}