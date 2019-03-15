# COMP9024

CC=gcc
CFLAGS=-Wall -Werror


Main : testList.o DLList.o
	$(CC) -o main testList.o DLList.o

DLList.o : DLList.c DLList.h
	$(CC) -c  DLList.c

testList.o : testList.c DLList.h
	$(CC) -c  testList.c

clean:
	rm -f main *.o core
