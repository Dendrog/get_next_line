#include <stdio.h>
#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

int main()
{
    char *a;
    int fd;
    fd = open("./t2.txt",O_RDONLY);
	//printf("%d",fd);
	//for(int i =0; i<1; i++){
		a = get_next_line(fd);
		printf("%s",a);
		free(a);
	//}
	close(fd);
}
