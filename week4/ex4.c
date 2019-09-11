#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	//with args
	char command[256];
	int i = 0;
	while(1){
		char temp;
		scanf("%c", &temp);
		if(temp == '\n' || temp == '\r'){
			command[i] = '\0';
			break;
		}
		command[i] = temp;
		i++;
	}
	system(command);
	return 0;
}