//--- MS C������ ��� ---------------
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 
//--------------------------------
#include <stdio.h>    

int main()
{
    char s1[100];
    int num1;

    FILE* fp = fopen("data3.txt", "r");
    fscanf(fp, "%s", s1); // �������� ������ �д´�. 
    printf("%s\n", s1);
    fclose(fp);

    return 0;
}