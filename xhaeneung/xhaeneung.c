#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_MAX 30+1
#define TC_MAX 10
#define TC_MIN 1

typedef struct _score{
	char *operand_str1;
	char *operand_str2;
	char *answer_str;
	char operator;
	int operand_int1;
	int operand_int2;
	int result;
} score_t;

char *my_gets(char*, int);
int convert_string_to_int(char *);
char *convert_int_to_string(int);
int check_string(char *, char *);
char find_operator(char *);
extern char *strtok_r(char *, const char *, char **);

int main(void)
{
	int tc_num, i;
	char *token;
	char *saveptr;
	char *out_str;
	char input_string[STRING_MAX]={0,};

	score_t **score_data;

	scanf("%d", &tc_num);
	getchar(); // for flushing stdin buffer

	// pointer initialize
	out_str = (char *)malloc(sizeof(char)*STRING_MAX);
	score_data = (score_t **)malloc(sizeof(score_t *)*tc_num);

	for(i=0; i<tc_num; i++){
		score_data[i] = (score_t *)malloc(sizeof(score_t));
		score_data[i]->operand_str1 = (char *)malloc(sizeof(char)*STRING_MAX);
		score_data[i]->operand_str2 = (char *)malloc(sizeof(char)*STRING_MAX);
		score_data[i]->answer_str = (char *)malloc(sizeof(char)*STRING_MAX);
	}

	for(i=0; i<tc_num; i++){
		// fgets함수를 이용해 stdin으로부터 입력을 받으면 \n문자까지 입력되기 때문에 \n을 \0으로 교체하는 api 사용
		strcpy(out_str, my_gets(input_string, STRING_MAX));

		// +,-,* 연산기호 찾기
		score_data[i]->operator = find_operator(out_str);

		// 연산 기호를 기준으로 문자열 parsing
		token = strtok_r(out_str, "+-*= ", &saveptr);
		strcpy(score_data[i]->operand_str1, token);
		token = strtok_r(saveptr, "+-*= ", &saveptr);
		strcpy(score_data[i]->operand_str2, token);
		token = strtok_r(saveptr, "+-*= ", &saveptr);
		strcpy(score_data[i]->answer_str, token);

		// string을 integer로 변환
		score_data[i]->operand_int1 = convert_string_to_int(score_data[i]->operand_str1);
		score_data[i]->operand_int2 = convert_string_to_int(score_data[i]->operand_str2);

		// 연산기호에 따라서 계산하기
		switch(score_data[i]->operator){
			case '+':
				score_data[i]->result = score_data[i]->operand_int1 + score_data[i]->operand_int2;
				break;

			case '*':
				score_data[i]->result = score_data[i]->operand_int1 * score_data[i]->operand_int2;
				break;

			case '-':
				score_data[i]->result = score_data[i]->operand_int1 - score_data[i]->operand_int2;
				break;
		}
	}

	for(i=0; i<tc_num; i++){
		// 채점 조건에 따라 10보다 크거나 0보다 작은 수는 오답처리
		if(score_data[i]->result > 10 || score_data[i]->result < 0){
			printf("No\n");
		}
		// 그 외 숫자에 대해서
		else{
			// 입력한 문자열과 계산 결과가 서로 anagram인지 확인하여
			// anagram일 경우 Yes 출력
			if(check_string(score_data[i]->answer_str, convert_int_to_string(score_data[i]->result))){
				printf("Yes\n");
			}
			// anagram아 아닐 경우No 출력
			else {
				printf("No\n");
			}

		}
	}

	// 할당한 자원 해제
	for(i=0; i<tc_num; i++){
		free(score_data[i]->operand_str1);
		free(score_data[i]->operand_str2);
		free(score_data[i]->answer_str);
		free(score_data[i]);
	}

	free(out_str);
	free(score_data);
}

char *my_gets(char *str, int size)
{
	int len, i;
	fgets(str, size, stdin);
	len = strlen(str);

	// 문자열의 끝까지
	for(i=0; i<len; i++){
		// 개행문자를 널문자로 변경
		if(str[i] == '\n')
			str[i] = '\0';
	}

	return str;
}

char find_operator(char *str)
{
	int len, i;
	char ret_val;
	len = strlen(str);
	
	// 입력형식이 정해져있기 때문에 연산기호는 하나만 찾으면 된다
	for(i=0; i<len; i++){
		if(str[i] == '+' || str[i] == '-' || str[i] == '*'){
			ret_val = str[i];
			break;
		}
	}
	
	return ret_val;
}

int convert_string_to_int(char *str)
{
	if(!strcmp(str, "zero")) return 0;
	else if(!strcmp(str, "one")) return 1;
	else if(!strcmp(str, "two")) return 2;
	else if(!strcmp(str, "three")) return 3;
	else if(!strcmp(str, "four")) return 4;
	else if(!strcmp(str, "five")) return 5;
	else if(!strcmp(str, "six")) return 6;
	else if(!strcmp(str, "seven")) return 7;
	else if(!strcmp(str, "eight")) return 8;
	else if(!strcmp(str, "nine")) return 9;
	else if(!strcmp(str, "ten")) return 10;
	else return -1;
}

char *convert_int_to_string(int num)
{
	if(num == 0) return "zero";
	else if(num == 1) return "one";
	else if(num == 2) return "two";
	else if(num == 3) return "three";
	else if(num == 4) return "four";
	else if(num == 5) return "five";
	else if(num == 6) return "six";
	else if(num == 7) return "seven";
	else if(num == 8) return "eight";
	else if(num == 9) return "nine";
	else if(num == 10) return "ten";
	else return NULL;
}

// 두 문자열이 서로 anagram 관계인지 확인하는 함수
int check_string(char *str1, char *str2)
{
	int i, x;
	int count1[128]={0,};
	int count2[128]={0,};

	// 문자열의 끝까지
	for(i=0; str1[i]; i++){
		x = str1[i] | 32; // char에 ascii코드 값을or 연산하여 배열의 index로 사용
		count1[x]++;
	}

	for(i=0; str2[i]; i++){
		x = str2[i] | 32;
		count2[x]++;
	}

	// 두 int 배열의 값이 같지 않으면 anagram 관계가 아니다
	for(i='a'; i<='z'; i++){
		if(count1[i] != count2[i]) break;
	}

	// 중간에 빠져나왔으면 anagram 관계가 아니기 때문에 
	// anagram 관계일 때에 i값은 z보다 크다.
	if(i > 'z') return 1;
	else return 0;
}
