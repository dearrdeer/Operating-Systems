#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

int main(){
	DIR *dir;
    struct dirent *entry;
    struct dirent *entries[100];
    int i = 0;

    dir = opendir("tmp/");

    while ( (entry = readdir(dir)) != NULL) {
        entries[i] = entry;
        i++;
    }

    int n = i;
    for(int i = 0; i < n-1; i++){
    	int min_i_node = entries[i]->d_ino;
    	int minind = i;
    	for(int j = i+1; j < n; j++){
    		if(entries[j]->d_ino < min_i_node){
    			min_i_node = entries[j]->d_ino;
    			minind = j;
    		}
    	}	
    	struct dirent *tempent = entries[i];
    	entries[i] = entries[minind];
    	entries[minind] = tempent;
    }
    
    for(int i = 0; i < n; i++){
    	int i_node = entries[i]->d_ino;
    	int j = i;
    	while(i_node == entries[j]->d_ino)j++;
    	if(j - i > 1){
    		printf("I_NODE: %d: FILENAMES: ", i_node);
    		for(int k = i; k < j; k++){	
    			printf("%s ", entries[k]->d_name);
    		}
    		printf("\n");
    	}
    	i=j;
    }
 
    closedir(dir);
	return 0;
}