//--- MS C에서만 사용 ---------------
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
    fscanf(fp, "%s", s1); // 서식으로 파일을 읽는다. 
    printf("%s\n", s1);
    fclose(fp);

    return 0;
}