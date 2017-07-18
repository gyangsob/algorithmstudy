#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_MAX (80+1)
#define TC_MAX 10
#define TC_MIN 1

char * adjust_string(char *, int);

int main(void)
{
	int tc_num=0;
	int i, j=0;
	char input_string[STRING_MAX], token[STRING_MAX];
	char **result;
	char *temp;

	scanf("%d", &tc_num);
	getchar();

	result = (char **)malloc(sizeof(char *)*tc_num);

	for(i=0; i<tc_num; i++){
		result[i] = (char *)malloc(sizeof(char)*STRING_MAX);
	}

	for(i=0; i<tc_num; i++) {
		j=0;
		scanf("%s", input_string);
		getchar();
		temp = input_string;
		// end of string
		while(temp[j] != '\0'){
			// check encoded token if  char of 'n' index == % and char of 'n+1' index == 2
			if(temp[j] == '%' && temp[j+1] && temp[j+1] == '2'){
				switch (temp[j+2]){
					case '0':
						// swap %20 to ' '
						temp[j] = ' ';
						temp = adjust_string(temp, j);
					break;

					case '1':
						// swap %21 to '!'
						temp[j] = '!';
						temp = adjust_string(temp, j);
					break;

					case '4':
						// swap %24 to '$'
						temp[j] = '$';
						temp = adjust_string(temp, j);
					break;

					case '5':
						// swap %25 to '%'
						temp[j] = '%';
						temp = adjust_string(temp, j);
					break;

					case '8':
						// swap %28 to '('
						temp[j] = '(';
						temp = adjust_string(temp, j);
					break;

					case '9':
						// swap %29 to ')'
						temp[j] = ')';
						temp = adjust_string(temp, j);
					break;

					case 'a':
						// swap %2a to '*'
						temp[j] = '*';
						temp = adjust_string(temp, j);
					break;
				}
			}
			j++;
		}
		strncpy(result[i], temp, strlen(temp));
		memset(input_string, '\0', STRING_MAX);
	}

	for(i=0; i<tc_num; i++){
		printf("%s\n", result[i]);
	}
}

// function name : adjust_string
// input : char *str, int index
// output : char *
// purpose : for strip string, after changing encoded character to decoded character
// index marks a position of '%' character before changing decoded character.
char * adjust_string(char *str, int index)
{
	char *ret_string;

	ret_string = (char *)malloc(sizeof(char)*(strlen(str)));

	// The decoded character remain using strncat from string[0] to string[index+1]
	strncat(ret_string, str, index+1);
	// and remove 2 more characters 
	strncat(ret_string, str+index+3, strlen(str)-index-3);
	return ret_string;
}
