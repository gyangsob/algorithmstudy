#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_MAX (100+1)

int check_anagram(char *, char *);
int check_string_order(char *, char *);

int main(void)
{
	int tc_num = 0;
	int i;
	char token1[STRING_MAX], token2[STRING_MAX];
	char **result;
	
	scanf("%d", &tc_num);
	getchar();

	result = (char **)malloc(sizeof(char *)*tc_num);

	for(i=0; i<tc_num; i++)
		result[i] = (char *)malloc(sizeof(char)*4);

	for(i=0; i<tc_num; i++){
		scanf("%s", token1);
		scanf("%s", token2);

		// check_anagram returns 1 if two strings are consist of same characters.
		// check anagram fisrt
		if(check_anagram(token1, token2)){
			// check_string_order returns 1 if two strings have difference order and same length
			if(check_string_order(token1, token2))
				strncpy(result[i], "No.", strlen("No."));
			else
				strncpy(result[i], "Yes", strlen("Yes"));
		}
		else
			strncpy(result[i], "No.", strlen("No."));
	}

	for(i=0; i<tc_num; i++){
		printf("%s\n", result[i]);
		free(result[i]);
	}

	free(result);
}

int check_anagram(char *str1, char *str2)
{
	int i;
	// integer array for marking alphanumeric : Upper case(26) + Lower case(26) + Numeric(10) 
	int count[62] = {0,};

	// increase array index
	for(i=0; str1[i]; i++){
		// Upper case
		if(str1[i] >= 'A' && str1[i] <= 'Z')
			count[str1[i]-65]++;
		// Lower case
		else if(str1[i] >= 'a' && str1[i] <= 'z')
			count[str1[i]-97+26]++;
		// Numeric
		else if(str1[i] >= '0' && str1[i] <= '9')
			count[str1[i]-48+52]++;
	}
	
	// decrease array index
	for(i=0; str2[i]; i++){
		// Upper case
		if(str2[i] >= 'A' && str2[i] <= 'Z')
			count[str2[i]-65]--;
		// Lower case
		else if(str2[i] >= 'a' && str2[i] <= 'z')
			count[str2[i]-97+26]--;
		// Numeric
		else if(str2[i] >= '0' && str2[i] <= '9')
			count[str2[i]-48+52]--;
	}

	// if count[index] is not zero, two strings are not anagram
	for(i=0; i<62; i++){
		if(count[i]) break;
	}

	if(i == 62)	return 1;
	else	return 0;
}

int check_string_order(char *str1, char *str2)
{
	if(strlen(str1) == strlen(str2) && strcmp(str1, str2) == 0)
		return 1;
	else
		return 0;
}
