#include<stdlib.h>
#include<stdio.h>
#include<sys/resource.h>

int main(){
	
	int size = 10*1024*1024;
	
	for(int i = 0; i < 10; i++){
		int *p = (int*)malloc(size);
		memset(p, 0, size);
		struct rusage r_usage;
		getrusage(RUSAGE_SELF, &r_usage);
		printf("Memory Usage: %d\n", r_usage.ru_maxrss);
		sleep(1);
	}
	return 0;
}