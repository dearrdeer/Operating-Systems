#include <stdio.h>
#include <string.h>

int str_to_int(char* str){
	int len = strlen(str);
	int res = 0;
	for(int i = 0; i < len; i++){
		res = res * 10 + (str[i]-'0');
	}
	return res;
}

int main(int argc, char* argv[]){
	int n = str_to_int(argv[1]);
	int height = n;
	int width = 2*n-1;
	for(int i = 0; i < height; i++){
		int dots_in_lane = 2*i+1;
		int spaces = (width - dots_in_lane)/2;
		for(int j = 0; j < spaces; j++){
			printf(" ");
		}
		for(int j = 0; j < dots_in_lane; j++){
			printf("*");
		}
		for(int j = 0; j < spaces; j++){
			printf(" ");
		}
		printf("\n");
	}
	return 0;
}