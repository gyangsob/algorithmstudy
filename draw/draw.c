#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int * p1_x;
	int * p2_x;
	int * p3_x;
	int * p1_y;
	int * p2_y;
	int * p3_y;
	int * p4_x;
	int * p4_y;
	int i, t;

	scanf("%d", &t);
	p1_x = (int *)malloc((sizeof(int))*t);
	p2_x = (int *)malloc((sizeof(int))*t);
	p3_x = (int *)malloc((sizeof(int))*t);
	p1_y = (int *)malloc((sizeof(int))*t);
	p2_y = (int *)malloc((sizeof(int))*t);
	p3_y = (int *)malloc((sizeof(int))*t);
	p4_x = (int *)malloc((sizeof(int))*t);
	p4_y = (int *)malloc((sizeof(int))*t);

	for(i=0; i < t; i++){
		scanf("%d %d",&p1_x[i], &p1_y[i]);
		scanf("%d %d",&p2_x[i], &p2_y[i]);
		scanf("%d %d",&p3_x[i], &p3_y[i]);
		p4_x[i] = p1_x[i] ^ p2_x[i] ^ p3_x[i];
		p4_y[i] = p1_y[i] ^ p2_y[i] ^ p3_y[i];
	}

	for(i=0; i<t; i++){
		printf("%d %d\n", p4_x[i], p4_y[i]);
	}
}
