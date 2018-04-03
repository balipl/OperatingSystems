#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "t.h"
 
#define BUFSIZE 1024
 
int main (int argc, char **argv) {
    int f1, c;  
    char b[BUFSIZE], *n1; //w b zapisujemy to co przeczytamy
 
    c = 10; //ile znakow czytamy
    n1 = argv[1]; //napis n1 jest argumentem(filename) przywywolywaniu programu
	timestart();
    f1 = open (n1, O_RDONLY);
	timestop("Funkcja open");
	if(f1 == -1){
		//printf("%s \n",strerror(errno));
		perror("Error: ");
		exit(EXIT_FAILURE);
	}
	//timestart();
    if(read (f1, b, c) == -1){
		//timestop("Funkcja read");
		printf("%s \n",strerror(errno));
		exit(EXIT_FAILURE);
	}
	
	
    printf("%s: Przeczytano %d znakow z pliku %s: \"%s\"\n",
	   argv[0], c, n1, b);
	
    close(f1);
 
    return(0);
}
