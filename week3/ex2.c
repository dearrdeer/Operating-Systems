#include <stdio.h>
#include <stdlib.h>

/*
	My implementation of bubble sort algo.
	Please, pass you array through terminal as arguments of main (via argc, argv)
*/

//Utill
int str_to_int(char *str){
	int res = 0;
	int i = 0;
	while(1){
		if(str[i] == '\0')return res;
		res *= 10;
		res += (str[i]-'0');
		i++;
	}
}

void bubble_sort(int* arr, int count){
	for(int i = 0; i < count-1; i++){
		for(int j = i; j < count-1; j++){
			if(arr[j] > arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int main(int argc, char* argv[]){
	int n = argc - 1;
	int* arr = (int*)malloc(sizeof(int)*n);
	//Reading the array
	for(int i = 0; i < n; i++){
		arr[i] = str_to_int(argv[i+1]);
	}
	//sort
	bubble_sort(arr, n);
	//print
	for (int i = 0; i < n; ++i){
		printf("%d ", arr[i]);
	}
	free(arr);
	return 0;
}