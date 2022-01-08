#include <stdio.h>
#include "get_next_line.h"
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd;
	char* str;
	fd = open("./sssss", O_RDWR);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = NULL;
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = NULL;
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = NULL;
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = NULL;
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = NULL;
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	return 0;
}