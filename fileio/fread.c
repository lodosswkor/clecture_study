//C언어 표준 라이브러리 함수 가이드
//size_t fwrite ( const void * base, size_t size, size_t count, FILE * fp); 파일 스트림에 데이터를 쓰는 함수
//회원 데이터 배열의 내용을 파일에 기록하고 다시 읽어와서 출력
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
        { "홍길동",20 },{ "강감찬",15 },{ "을지문덕",22 },{ "이순신",19 },{ "김구",30 },
        { "안중근",30 },{ "박찬호",35 },{ "김연아",17 },{ "아이유",20 },{ "주니엘",20 }
    };
    Member members2[MAX_MEMBERS];

    //쓰기 모드로 파일 열기
    fopen_s(&fp, "data.txt", "w");
    if (fp == NULL)
    {
        perror("error fopen");
        return;
    }
    //출력 파일 스트림에 members 배열의 내용 출력
    if (fwrite(members, sizeof(Member), MAX_MEMBERS, fp) != MAX_MEMBERS)
    {
        printf("출력 오류\n");
        return;
    }
    fclose(fp);//출력 파일 스트림 닫기

   //읽기 모드로 파일 열기
    fopen_s(&fp, "data.txt", "r");
    if (fp == NULL)
    {
        perror("error fopen");
        return;
    }

    //파일에서 members2 배열로 데이터 읽기
    fread(members2, sizeof(Member), MAX_MEMBERS, fp);
    //읽어온 데이터 출력
    printf("%-10s %-10s\n", "이름", "나이");
    for (i = 0; i < MAX_MEMBERS; i++)
    {
        printf("%-10s %-10d\n", members2[i].name, members2[i].age);
    }
    fclose(fp); //입력 파일 스트림 닫기
    return 0;
}