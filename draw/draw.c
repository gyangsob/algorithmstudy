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

	// 입력받은 TC개수만큼 int 변수 dynamic allocation
	p1_x = (int *)malloc((sizeof(int))*t);
	p2_x = (int *)malloc((sizeof(int))*t);
	p3_x = (int *)malloc((sizeof(int))*t);
	p1_y = (int *)malloc((sizeof(int))*t);
	p2_y = (int *)malloc((sizeof(int))*t);
	p3_y = (int *)malloc((sizeof(int))*t);
	p4_x = (int *)malloc((sizeof(int))*t);
	p4_y = (int *)malloc((sizeof(int))*t);

	for(i=0; i < t; i++){
		// 3개의 꼭지점 정보 입력
		scanf("%d %d",&p1_x[i], &p1_y[i]);
		scanf("%d %d",&p2_x[i], &p2_y[i]);
		scanf("%d %d",&p3_x[i], &p3_y[i]);
		
		// 남은 한 점의 좌표는  세점을 xor 연산한 결과
		p4_x[i] = p1_x[i] ^ p2_x[i] ^ p3_x[i];
		p4_y[i] = p1_y[i] ^ p2_y[i] ^ p3_y[i];
	}

	for(i=0; i<t; i++){
		printf("%d %d\n", p4_x[i], p4_y[i]);
	}

	// 할당한 변수 해제
	free(p1_x);
	free(p2_x);
	free(p3_x);
	free(p1_y);
	free(p2_y);
	free(p3_y);
	free(p4_x);
	free(p4_y);
}
