#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strcmp, strncmp 

#define IN_BUFFER_SIZE 100
#define INIT_CAPACITY 3

//-- Boolean Enum 
typedef enum _bool {
	false = 0,
	true
} Bool;

/* add */
void init_bookshelf();
int command_read(char , int );
/* =========== */

void add(book_no, book_name, book_author);
void delete();
void list();
void find();
void help();

void readFile();
void saveFile();


//int book_no[CAPACITY];
//char* book_name[CAPACITY];
//char* book_author[CAPACITY];
char** book_no;
char** book_name;
char** book_author;
int capacity = INIT_CAPACITY;
int book_cnt = 0;

int main(void) {

	char cmd_line[IN_BUFFER_SIZE];
	char seperator[] = " ";

	char* command, * arg1, *arg2, * arg3;

	while (true) {

		printf("> ");

		if (read_line(cmd_line, IN_BUFFER_SIZE) <= 0) {
			continue; 
		}

		command = strtok(cmd_line, seperator); 
		if (command == NULL) {
			continue;
		}

		if (strcmp(command, "add") == 0) {
			arg1 = strtok(cmd_line, seperator);
			arg2 = strtok(cmd_line, seperator);
			arg3 = strtok(cmd_line, seperator);

			add();
		}
		else if (strcmp(command, "find") == 0) {
			find();
		}
		else if (strcmp(command, "list") == 0) {
			list();
		}
		else if (strcmp(command, "delete") == 0) {
			delete();
		}
		else if (strcmp(command, "h") == 0) {
			help();
		}
		else if (strcmp(command, "read") == 0) {
			readFile();
		}
		else if (strcmp(command, "save") == 0) {
			saveFile();
		}
		else if (strcmp(command, "quit") == 0) {
			break;
		}
		else {
			printf("잘못된 명령어를 입력하였습니다. ex) add/delete/find/list \n");
		}

		scanf("%s\n", cmd); //-- Enter 삭제 
	}

	return 0;
}

void init_bookself() {
	book_no = (int**)malloc(INIT_CAPACITY * sizeof(int*));
	book_name = (char**)malloc(INIT_CAPACITY * sizeof(char*));
	book_author = (char**)malloc(INIT_CAPACITY * sizeof(char*));
}

int command_read(char str[], int limit) {
	int ch, i = 0;
	while ((ch = getchar()) != '\n') {
		if (i < limit - 1) {
			str[i++] = ch;
		}
	}
	str[i] = '\0';
	return i; 
}

void add(book_no, book_name, book_author) {

	if (book_cnt = capacity) reallocate(); 
	int i = book_cnt - 1; 

	while (i >= 0 && strcmp(book_no[i], book_no) > 0) {
		book_name[i + 1] = book_name[i]; 
		book_author[i + 1] = book_author[i];
		book_no[i + 1] = book_author[i];
		i--;
	}

	book_name[i + 1] = _strdup(book_name);
	book_author[i + 1] = _strdup(book_author);
	book_no[i + 1] = _strdup(book_no);
	book_cnt++; 
}

void reallocate() {

	int i; 
	capacity *= 2; 
	char** tmp1 = (char**)malloc(capacity * sizeof(char*));

	for (i = 0; i < book_cnt; i++) {
	
	}

	free(names);
	free(numbers);

	names = tmp1; 

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
	printf("책 목록중에 '%s' 라는 책은 존재하지 않습니다!\n", str1);
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
			printf("%d '%s' 가 삭제되었습니다.\n", target_no, book_name[i]);
			return;
		}
	}
	printf("번호가 %d 인 서적은 존재하지 않습니다.\n");

}

void list() {
	for (int i = 0; i < book_cnt; i++) {
		printf("%d\t%s\t%s\n", book_no[i], book_name[i], book_author[i]);
	}
}

void help() {
	printf("---------------------------------\n");
	printf("책추가 : add 책번호 책이름 작가 [엔터]\n");
	printf("책삭제 : del 책번호 [엔터]\n");
	printf("---------------------------------\n");
}

void readFile() {
	char fileName[IN_BUFFER_SIZE];
	char  str2[IN_BUFFER_SIZE], str3[IN_BUFFER_SIZE];
	int no = 0;

	scanf("%s", fileName);
	FILE* fp = fopen(fileName, "r");
	if (fp == NULL) {
		printf("파일 %s 을 여는데 실패하였습니다.\n", fileName);
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