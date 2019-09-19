#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#define MAX_GOODS 5

int goods = 0;
pthread_t *producer, *consumer;

void *produce(){
	while(1){
		if(goods == MAX_GOODS){
			sleep(10);
		}else{
			goods++;
		}
	}
	pthread_exit(NULL);
}

void *consume(){
	while(1){
		if(goods == 0){
			sleep(10);
		}else{
			goods--;
		}
	}
	prthread_exit(NULL);
}

int main(){
	pthread_create(&producer, NULL, produce, NULL);
	pthread_create(&consumer, NULL, consume, NULL);

	while(1){
		sleep(60);
		printf("%d\n", goods);
	}
	return 0;
}