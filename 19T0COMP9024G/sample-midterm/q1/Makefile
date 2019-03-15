# Question: subsetList

CC=gcc
CFLAGS=-Wall -Werror

all: testSubsetList

testSubsetList : DLList.o  subsetList.o testSubsetList.o
	$(CC) -o testSubsetList  DLList.o  subsetList.o testSubsetList.o

subsetList.o : subsetList.c   DLList.h 

testSubsetList.o : testSubsetList.c   DLList.h 

clean:
	rm -f testSubsetList subsetList.o testSubsetList.o core
