#include <stdio.h>
#include <stdlib.h>

#define buffer_size 128

int main(){
	char buffer[buffer_size];

	setvbuf(stdout, buffer, _IOLBF, buffer_size);

	printf("H");
	printf("e");
	printf("l");
	printf("l");
	printf("o");

	sleep(5);
	printf("\n");
	return 0;
}