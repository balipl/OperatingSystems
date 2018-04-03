/*
 * copy1.c
 * 
 * based on: 
 *
 * Miscellaneous examples for Chap. 2
 * AUP2, Chap. 2
 *
 * modified by WTA
 */

/*[copy-with-bug]*/

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

void copy(char *from, char *to)  /* has a bug */
{
	int fromfd = -1, tofd = -1;
	ssize_t nread,nwrite;
	char buf[BUFSIZE];
	
	fromfd = open(from, O_RDONLY);
	if(fromfd == -1){
		perror("Error:");
	}
	tofd = open(to, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if(tofd == -1){
		perror("Error:");
	}
	nread = readall(fromfd, buf,sizeof(buf));
	printf("XXXX %zd XXXX",nread);
	nwrite = writeall(tofd, buf, sizeof(buf));
	printf("YYYY %zd YYYYY",nwrite);
        close(fromfd);
	close(tofd);
	return;
}

int main(int argc, char **argv){
	if (argc != 3)
	{
		fprintf(stderr,"usage: %s from_pathname to_pathname\n", argv[0]);
		return 1;
	}
	copy(argv[1], argv[2]);
	return 0;
}
