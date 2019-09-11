#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	//without args
	char command[256];
	scanf("%s", command);
	system(command);
	return 0;
}