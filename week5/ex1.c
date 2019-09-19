#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void * PrintHello(int i) {
	printf("Hello from thread %d - I was created in iteration %d !\n",(int) pthread_self(), i);
	// The function's return value serves as the thread's exit status
	// pubs.opengroup.org/onlinepubs/7908799/xsh/pthread_exit.html
	pthread_exit(NULL);
}

int main(){
	printf("Enter the count of threads:\n");
	int n;
	scanf("%d", &n);
	pthread_t *r;
	malloc(sizeof(pthread_t) * n);
	int rc = 0;
	for(int i = 0; i < n; i++){
		if (pthread_create(&r[i], NULL, PrintHello, i)) {
			printf("\n ERROR: return code from pthread_create is %d \n", rc);
			exit(1);
		}
		printf("\n I am thread %d. Created new thread (%d) in iteration %d ...\n",(int) pthread_self(), i, i);
		sleep(5);//This is making the threads execute each one by one
	}
	pthread_exit(NULL);
	free(r);
	return 0;
}