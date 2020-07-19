#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char* argv[])
{
	FILE *fd1, *fd2;
	uint32_t num1=0;
	uint32_t num2=0;
	uint32_t ans=0;
	if ( argc < 3 ) {
		printf("Usage : %s <filename1> <filename2>\n", argv[0]);
		return 0;
	}
	fd1= fopen(argv[1], "r");
	fd2= fopen(argv[2], "r");
	fread(&num1, sizeof(uint32_t), 1, fd1);
	fread(&num2, sizeof(uint32_t), 1, fd2);
	num1=ntohl(num1);
	num2=ntohl(num2);
	ans= num1+num2;
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1, num1, num2, num2, ans, ans);
	fclose(fd2);
	fclose(fd1);
	return 0;
}