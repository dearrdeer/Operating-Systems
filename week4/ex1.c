#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	char* n = argv[1];
	if(fork()==0){
		printf("Hello from child [%d - %s]\n",getpid(), n);
	}else{
		printf("Hello from parent [%d - %s]\n",getpid(), n);
	}
	return 0;
}