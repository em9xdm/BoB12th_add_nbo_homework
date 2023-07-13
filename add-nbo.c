#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		puts("syntax : add-nbo <file1> <file2>");
		puts("sample : add-nbo a.bin b.bin");
		return 0;
	}
	uint32_t one, two, result;
	FILE *fp1 = fopen(argv[1], "rb");
	FILE *fp2 = fopen(argv[2], "rb");
	
	fread(&one, sizeof(one), 1, fp1);
	fread(&two, sizeof(two), 1, fp2);

	one = ntohl(one); // NBO - Big Endian; convert NBO to HBO LE
	two = ntohl(two); // NBO - Big Endian; convert NBO to HBO LE
	result = one + two;

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", one, one, two, two, result, result);

	fclose(fp1);
	fclose(fp2);
	return 0;
}
