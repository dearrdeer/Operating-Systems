#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int getmin(int a, int b)
{
    return a<b?a:b;
}


void *reallocation(void *ptr, size_t size, size_t old_size) //size_t in bytes
{

    void *newptr;

    int msize;

    msize = getmin(old_size, size);

    if(size == 0){
    	free(ptr);
    	return NULL;
    }
    newptr = malloc(size);
    newptr = memcpy(newptr, ptr, msize);
    free(ptr);

    return newptr;
}
int main(){
	int* p = (int*)reallocation(p, sizeof(int)*3, 0);
	for(int i = 0; i < 3; i++){
		p[i] = i;
	}
	p = (int*)reallocation(p,sizeof(int)*5, sizeof(int)*3);
	for (int i = 0; i < 5; ++i)
	{
		printf("%d\n", p[i]);
	}
	return 0;
}