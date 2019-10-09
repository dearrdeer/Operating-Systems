#include<stdlib.h>
#include<stdio.h>

int main(){
	
	int size = 100*1024*1024;
	/*
	In my PC allocating 10 MBs is not enough for memory to begin swapping
	Also tried 100 mb which was also too small, and only when increased it to 1000
	I have noticed the changing of si and so, but a few seconds later I had to make hard reboot) 
	
	In the exercise 3, when running with 10 mbs, the process is in 8-9th places, when it is 100 mbs it is 3
	(Web Browser is always 1st). Did not checked with 1000)
	*/
	for(int i = 0; i < 10; i++){
		int *p = (int*)malloc(size);
		memset(p, 0, size);
		sleep(1);
	}
	return 0;
}