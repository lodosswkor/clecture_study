//C��� ǥ�� ���̺귯�� �Լ� ���̵�
//size_t fwrite ( const void * base, size_t size, size_t count, FILE * fp); ���� ��Ʈ���� �����͸� ���� �Լ�
//ȸ�� ������ �迭�� ������ ���Ͽ� ����ϰ� �ٽ� �о�ͼ� ���
#include <stdio.h>

#define MAX_NAME_LEN    20
typedef struct {
    char name[MAX_NAME_LEN + 1];
    int age;
}Member;

#define MAX_MEMBERS 10
int main05(void)
{
    FILE* fp;
    int i;
    Member members[MAX_MEMBERS] =
    {
        { "ȫ�浿",20 },{ "������",15 },{ "��������",22 },{ "�̼���",19 },{ "�豸",30 },
        { "���߱�",30 },{ "����ȣ",35 },{ "�迬��",17 },{ "������",20 },{ "�ִϿ�",20 }
    };
    Member members2[MAX_MEMBERS];

    //���� ���� ���� ����
    fopen_s(&fp, "data.txt", "w");
    if (fp == NULL)
    {
        perror("error fopen");
        return;
    }
    //��� ���� ��Ʈ���� members �迭�� ���� ���
    if (fwrite(members, sizeof(Member), MAX_MEMBERS, fp) != MAX_MEMBERS)
    {
        printf("��� ����\n");
        return;
    }
    fclose(fp);//��� ���� ��Ʈ�� �ݱ�

   //�б� ���� ���� ����
    fopen_s(&fp, "data.txt", "r");
    if (fp == NULL)
    {
        perror("error fopen");
        return;
    }

    //���Ͽ��� members2 �迭�� ������ �б�
    fread(members2, sizeof(Member), MAX_MEMBERS, fp);
    //�о�� ������ ���
    printf("%-10s %-10s\n", "�̸�", "����");
    for (i = 0; i < MAX_MEMBERS; i++)
    {
        printf("%-10s %-10d\n", members2[i].name, members2[i].age);
    }
    fclose(fp); //�Է� ���� ��Ʈ�� �ݱ�
    return 0;
}