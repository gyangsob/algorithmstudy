#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_MAX 100+1

char * enc_str(char *);

int main(void)
{
	int tc_num, i;
	char input_string[STRING_MAX]={0,};
	char **out_str;

	scanf("%d", &tc_num);

	out_str=(char**)malloc(sizeof(char*)*tc_num);

	for(i=0; i<tc_num; i++) {
		out_str[i]=(char*)malloc(sizeof(char)*STRING_MAX);
		memset(out_str[i], 0, sizeof(char)*STRING_MAX);

		scanf("%s", input_string);

		out_str[i] = enc_str(input_string);
	}

	for(i=0; i<tc_num; i++)
		printf("%s\n", out_str[i]);
	

	// free memory
	for(i=0; i<tc_num; i++) {
		free(out_str[i]);
	}
	free(out_str);
}

char *enc_str(char *input_string)
{
	int i;
	char *output_string;

	output_string = (char*)malloc(sizeof(char)*STRING_MAX);

	// first, add charater where located even index
	for(i=0; i<strlen(input_string); i++){
		if(i%2==0) // even number
			strncat(output_string, input_string+i, 1);
	}

	// and add charater where located odd index
	// this way is valid because feature of strncat function : strncat return resulting destination pointer.
	for(i=0; i<strlen(input_string); i++){
		if(i%2==1) // odd number
			strncat(output_string, input_string+i, 1);
	}

	return output_string;

}
