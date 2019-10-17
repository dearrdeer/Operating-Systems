#include<stdlib.h>
#include<stdio.h>
#include<sys/resource.h>

#define PAGE_FRAMES 10
#define file_name "Lab 09 input.txt"

int main(){
	FILE *file;
	file = fopen(file_name, "r");

	int pages[PAGE_FRAMES];
	unsigned short int ages[PAGE_FRAMES]; 

	for(int i = 0; i < PAGE_FRAMES; i++){
		pages[i] = -1; //-1 is free
		ages[i] = 0;
	}

	int hits = 0;
	int misses = 0;
	while(1){
		int reference;
		fscanf(file, "%d", &reference);

		int found = 0; //Boolean if find a place for page (or its already in table)
		for(int i = 0; i < PAGE_FRAMES; i++){
			ages[i] = ages[i] >> 1; //Resest all counters
			if(found == 0 && (pages[i] == -1 || pages[i] == reference)){
				
				if(pages[i] == -1)misses++;
				else hits++;

				pages[i] = reference;
				ages[i] = ages[i] | (1 << 15); // Add 1 from the left
				found = 1;
			}
		}
		if(found == 0){
			//Page is not in the table, and table is full, so we must erase one page
			misses++;
			int min_ind = 0;
			for(int i = 0; i < PAGE_FRAMES; i++){
				if(ages[i] < ages[min_ind]){
					min_ind = i;
				}
			}
			pages[min_ind] = reference;
			ages[min_ind] = (1 << 15);
		}
		char c = fgetc(file);
		if(c == EOF || c == '\n' || c == '\r')break;
	}
	printf("Hits: %d,  Misses: %d, Ratio: %f\n", hits, misses, (double)hits/(double)misses);
	return 0;
}