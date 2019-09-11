#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	for(int i = 0; i < 3; i++){
		fork();
		system("sleep 5");
	}
	return 0;
}

/*
	Original process will create 3 proccesses , one of them will also create 2 proccess
	another 1 proccess. So each process will create another processes depending on which 
	iteration the process itself was created. The pstree picture will remind half of the 
	pyramid.
*/