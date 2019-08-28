#include <stdio.h>
#include <float.h>
#include <limits.h>

int main(){
	int integer_var = INT_MAX;
	float float_var = FLT_MAX;
	double double_var = DBL_MAX;
	printf("Max value of integer: %d. Size of the variable: %ld\n", integer_var, sizeof(integer_var));
	printf("Max value of float: %f. Size of the variable: %ld\n", float_var, sizeof(float_var));
	printf("Max value of double: %f. Size of the variable: %ld\n", double_var, sizeof(double_var));
	return 0;
}