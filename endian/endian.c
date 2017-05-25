#include <stdio.h>

// defint macro 
// bit shift operation to change big endian to little endian

// [X000] --> [000X] : 0xff000000 마스킹 후 3바이트	right shift 
// [0X00] --> [00X0] : 0x00ff0000 마스킹 후 1바이트 right shift
// [00X0] --> [0X00] : 0x0000ff00 마스킹 후 1바이트 left shift
// [000X] --> [X000] : 0x000000ff 마스킹 후 3바이트 left shift
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
