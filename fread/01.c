//--- MS C������ ��� ---------------
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 
//--------------------------------
#include <stdio.h>


struct score
{
    char name[20];
    double kor, eng, total;
};

typedef struct score STUDENT;

int main(void)
{
    STUDENT s, ss;
    FILE* stream;

    printf("1. �̸� �Է� : ");
    fscanf(stdin, "%s", s.name);

    printf("2. ���� ����, ���� ���� �Է� : ");
    fscanf(stdin, "%lf %lf", &s.kor, &s.eng);
    s.total = s.kor + s.eng;

    stream = fopen("student.dat", "w");
    if (stream != NULL)
    {
        fwrite(&s, sizeof(s), 1, stream);
        fclose(stream);
    }
    else
    {
        puts("���� ���� ����");
    }

    stream = fopen("student.dat", "r");
    
    if (stream != NULL)
    {
        fread(&ss, sizeof(ss), 1, stream);
        fprintf(stdout, "%s %.2lf %.2lf %.2lf\n", ss.name, ss.kor, ss.eng, ss.total);
        fclose(stream);
    }
    else
    {
        puts("���� ���� ����");
    }

    return 0;
}