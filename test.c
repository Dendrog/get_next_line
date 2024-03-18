#include <stdio.h>
#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

int main()
{
    char *a;
    int fd;
    fd = open("./txt.txt",O_RDONLY);
	a = get_next_line(fd);
	printf("%s",a);
	free(a);
	a = get_next_line(fd);
	//printf("%s",a);
	free(a);
	a = get_next_line(fd);
	//printf("%s",a);
	free(a);
	a = get_next_line(fd);
	printf("%s",a);
	free(a);
	close(fd);
}