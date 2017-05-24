#include <stdio.h>

#define SWAP32(l) \
	( ((((l) & 0xff000000) >> 24) | \
	   (((l) & 0x00ff0000) >> 8) | \
	   (((l) & 0x0000ff00) << 8) | \
	   (((l) & 0x000000ff) << 24)))

int main(void)
{
	unsigned int l;
	unsigned int num;

	scanf("%d", &num);

	while(num>0) {
		scanf("%u", &l);
		printf("%u\n", SWAP32(l));
		num--;
	}
	
}
