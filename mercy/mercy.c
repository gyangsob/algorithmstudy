#include <stdio.h>

int main(void)
{
	unsigned int input_num; // Input contains just one positive integer N
	scanf("%d", &input_num);

	while(input_num > 0) {
		printf("Hello Algospot!\n");
		input_num--;
	}
	
	return 0;
}
