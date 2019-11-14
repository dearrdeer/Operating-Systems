#include <stdio.h>
#include <unistd.h>
#include <sys/io.h>
#include <stdlib.h>

int less_or_equal(int A[3], int B[3]){
	for(int i = 0; i < 3; i++){
		if(A[i] > B[i])return 0;
	}
	return 1;
}

void release(int A[3], int B[3]){
	for(int i = 0; i < 3; i++){
		B[i] += A[i];
	}
}

int main(){
	FILE *fp, *fp_out;
	if((fp = fopen("input.txt", "r")) == NULL){
		printf("Can not open file!");
		exit(1);
	}
	fp_out = fopen("output.txt", "w");
	int E[3], A[3], C[5][3], R[5][3];
	char temp;
	fscanf(fp, "%d %d %d\n", &E[0], &E[1], &E[2]);
	fscanf(fp, "\n");
	fscanf(fp, "%d %d %d\n", &A[0], &A[1], &A[2]);
	fscanf(fp, "\n");

	for(int i = 0; i < 5; i++){
		fscanf(fp, "%d %d %d\n", &C[i][0], &C[i][1], &C[i][2]);
	}
	fscanf(fp, "\n");

	for(int i = 0; i < 5; i++){
		fscanf(fp, "%d %d %d\n", &R[i][0], &R[i][1], &R[i][2]);
	}
	int released[5];
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			if(released[j] != 1 && less_or_equal(R[j], A)){	
				release(C[j], A); 
				released[j] = 1;
			}
		}
	}
	int locked = 0;
	for(int i = 0; i < 5; i++){
		if(released[i] != 1){
			fprintf(fp_out, "%d ", i);
			locked++;
		}
	}
	if(locked == 0){
		fprintf(fp_out, "No deadlocks!");
	}else{
		fprintf(fp_out, "\n%d Deadlocks", locked);
	}
	return 0;
}