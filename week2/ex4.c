#include<stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	int a,b;
	printf("Enter 2 numbers: ");
	scanf("%d %d", &a, &b);
	swap(&a, &b);
	printf("%d %d\n",a ,b);
	return 0;
}