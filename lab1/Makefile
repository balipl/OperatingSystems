all: ex1open clean

ex1open: ex1open.o t.o t.h
		gcc -o ex1open ex1open.o t.o

ex1open.o: ex1open.c
		gcc -c -o ex1open.o ex1open.c

t.o: t.c t.h
		gcc -c -o t.o t.c
clean:
		rm -f ex1open.o		
		rm -f *~
		rm -f *.bak

.PHONY: clean
