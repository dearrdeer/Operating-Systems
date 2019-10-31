#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]){
    int fd, offset;
    char *region;
    struct stat sbuf;
     
    if ((fd = open("ex1.txt", O_RDWR)) == -1) {
        perror("open");
        exit(1);
    }

   if (stat("ex1.txt", &sbuf) == -1) {
        perror("stat");
        exit(1);
    }
    
    if(ftruncate(fd, 19) == -1){
      perror("ftruncate");
      exit(1);
    }

    if ((region = mmap((caddr_t)0, sbuf.st_size, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0)) == (caddr_t)(-1)) {
        perror("mmap");
        exit(1);
    }

    strcpy(region, "This is a nice day!");

    return 0;
  }
