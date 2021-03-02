#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strcmp, strncmp 

#define IN_BUFFER_SIZE 100
#define CAPACITY 100

//-- Boolean Enum 
typedef enum _bool{
   false = 0,
   true
} Bool; 

void add();
void delete();
void list();
void find();
void help(); 

void readFile();
void saveFile();


int book_no[CAPACITY];
char* book_name[CAPACITY];
char* book_author[CAPACITY];
int book_cnt = 0;

int main(void) {

	char cmd[IN_BUFFER_SIZE]; 

	while (true) {

		printf("> "); 
		scanf("%s", cmd);
	
		if (strcmp(cmd, "add") == 0) {
			add(); 
		}
		else if (strcmp(cmd, "find") == 0) {
			find(); 
		}
		else if (strcmp(cmd, "list") == 0) {
			list();
		} 
		else if(strcmp(cmd, "delete") == 0) {
			delete(); 
		} 
		else if (strcmp(cmd, "h") == 0) {
			help(); 
		}
		else if (strcmp(cmd, "read") == 0) {
			readFile();
		}
		else if (strcmp(cmd, "save") == 0) {
			saveFile();
		}
		else if (strcmp(cmd, "quit") == 0) {
			break;
		}
		else {
			printf("�߸��� ��ɾ �Է��Ͽ����ϴ�. ex) add/delete/find/list \n");
		}

		scanf("%s\n", cmd); //-- Enter ���� 
	}

	return 0; 
}


void add() {

	char str1[IN_BUFFER_SIZE], str2[IN_BUFFER_SIZE]; 

	scanf("%s", str1); 
	scanf("%s", str2);

	book_no[book_cnt] = book_cnt + 1;
	//book_name[book_cnt] = strcpy(book_name[book_cnt], str1); <-- error
	book_name[book_cnt] = _strdup(str1); //str1;  //book_name[book_cnt] = strcpy(book_name[book_cnt], str1);
	book_author[book_cnt] = _strdup(str2); // str2;
	printf("%d, %s, %s �� �����Ͽ����ϴ�.\n", book_no[book_cnt], book_name[book_cnt], book_author[book_cnt]);
	book_cnt++;
}

void find() {
	char str1[IN_BUFFER_SIZE];
	scanf("%s", str1); 
	
	for (int i = 0; i < book_cnt; i++) {
		if (strcmp(str1, book_name[i]) == 0) {
			printf("%d, %s, %s", book_no[i], book_name[i], book_author[i]);
			return; 
		}
	}
	printf("å ����߿� '%s' ��� å�� �������� �ʽ��ϴ�!\n",  str1);
}

void delete() {
	int target_no;
	scanf("%d", &target_no);

	for (int i = 0; i < book_cnt; i++) {
		if (book_no[i] == target_no) {
			book_no[i] = book_no[book_cnt - 1];
			book_name[i] = book_name[book_cnt - 1];
			book_author[i] = book_author[book_cnt - 1];
			book_cnt--;
			printf("%d '%s' �� �����Ǿ����ϴ�.\n", target_no , book_name[i]);
			return;
		}
	}
	printf("��ȣ�� %d �� ������ �������� �ʽ��ϴ�.\n");

}

void list() {
	for (int i = 0; i < book_cnt; i++) {
		printf("%d\t%s\t%s\n", book_no[i], book_name[i], book_author[i]);
	}
}

void help() {
	printf("---------------------------------\n");
	printf("å�߰� : add å��ȣ å�̸� �۰� [����]\n");
	printf("å���� : del å��ȣ [����]\n");
	printf("---------------------------------\n");
}

void readFile() {
	char fileName[IN_BUFFER_SIZE];
	char  str2[IN_BUFFER_SIZE], str3[IN_BUFFER_SIZE];
	int no = 0; 

	scanf("%s", fileName);
	FILE* fp = fopen(fileName, "r"); 
	if (fp == NULL) {
		printf("���� %s �� ���µ� �����Ͽ����ϴ�.\n", fileName);
		return; 
	}

	while (fscanf(fp, "%d", &no) != EOF) {
		fscanf(fp, "%s", str2); 
		fscanf(fp, "%s", str3);

		book_no[book_cnt] = no;
		book_name[book_cnt] = _strdup(str2); //str1;  //book_name[book_cnt] = strcpy(book_name[book_cnt], str1);
		book_author[book_cnt] = _strdup(str3); // str2;'
		book_cnt++;
	}

	printf("load ended\n");
	fclose(fp);
}

void saveFile() {
	char fileName[IN_BUFFER_SIZE];

	scanf("%s", fileName); 

	FILE* fp = fopen(fileName, "w"); 
	if (fp == NULL) {
		printf("Error!");
		return; 
	}

	for (int i = 0; i < book_cnt; i++) {
		fprintf(fp, "%d %s %s\n", book_no[i], book_name[i], book_author[i]);
	}

	fclose(fp);
}