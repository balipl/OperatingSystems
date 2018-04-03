

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "readall.h"
#include "writeall.h"

#define BUFSIZE 512

int main(int argc, char **argv){
	if (argc != 2)
	{
		fprintf(stderr,"usage: %s pathname\n", argv[0]);
		return 1;
	}
	int fd;
	char buf[BUFSIZE];
	fd = open(argv[1], O_RDONLY);
	readall(fd, buf, sizeof(buf));
	writeall(1, buf, sizeof(buf));
	return 0;
}
