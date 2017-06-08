#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_MAX 1000+1
#define TC_MAX 10
#define TC_MIN 1

char * miss_spell(int, char *);

int main(void)
{
	int i;
	int miss_spell_num;
	int tc_num;

	char input_string[STRING_MAX];
	char **out_str;

	scanf("%d", &tc_num);

	out_str = (char **)malloc(sizeof(char *)*tc_num);

	for(i=0; i<tc_num; i++){
		out_str[i] = (char *)malloc(sizeof(char)*STRING_MAX);
	}

	for(i=0; i<tc_num; i++) {
		scanf("%d %s", &miss_spell_num, input_string);
		out_str[i] = miss_spell(miss_spell_num, input_string);
	}

	for(i=0; i<tc_num; i++) {
		printf("%d %s\n", i+1, out_str[i]);
	}

	for(i=0; i<tc_num; i++) {
		free(out_str[i]);
	}
	free(out_str);

	return 0;
}

char *miss_spell(int miss_spell_num, char *input_string)
{
	char *return_string;

	return_string = (char *)malloc(sizeof(char)*STRING_MAX);

	// return_string에 input_string의 시작주소부터 제거할 문자가 있는 위치-1까지 붙여넣는다
	strncat(return_string, input_string, miss_spell_num-1);
	// return_string에 제거할 문자 다음 위치부터 문자열의 끝까지 붙여넣는다
	// 전체 문자열의 길이에서 제거할 문자의 위치를 뺀 뒤 1을 더하면 남은 문자열 개수를 구할 수 있다
	// strncat은 dest 문자열의 결과를 리턴한다 == 붙여넣은 문자개수만큼 이동된 주소를 리턴한다.
	strncat(return_string, input_string+miss_spell_num, strlen(input_string)-miss_spell_num+1);

	return return_string;
}
