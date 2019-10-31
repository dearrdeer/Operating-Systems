#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>


int main(){
	int fd_source = open("ex1.txt", O_RDWR);
	int fd_dest = open("ex1.memcpy.txt", O_RDWR);

	struct stat s_source;
	
	if(fd_source == -1 || fd_dest == -1){
		perror("open");
		exit(1);
	}

	if(stat("ex1.txt", &s_source) == -1){
		perror("stat");
		exit(1);
	}
	
	if(ftruncate(fd_dest, s_source.st_size) == -1){
		perror("ftruncate");
		exit(1);
	}

	char *source_region = mmap((caddr_t) 0, s_source.st_size, PROT_READ, MAP_SHARED, fd_source, 0);
	char *dest_region = mmap((caddr_t) 0, s_source.st_size, PROT_WRITE, MAP_SHARED, fd_dest, 0);

	if(source_region == (caddr_t)-1 || dest_region == (caddr_t) -1){
		perror("mmap");
		exit(1);
	}
	memcpy(dest_region, source_region, s_source.st_size);
	return 0;
}