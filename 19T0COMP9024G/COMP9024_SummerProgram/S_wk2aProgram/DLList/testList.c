// testList.c - testing DLList data type

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "DLList.h"

int main(int argc, char *argv[])
{
	int value = 0; 	

	DLList myList = newDLList();
	DLListAfter( myList, 2);
	DLListAfter( myList, 5);
	DLListAfter( myList, 6);
	DLListAfter( myList, 8);
	DLListAfter( myList, 9);
	DLListBefore( myList, 12);
	DLListBefore( myList, 15);
	DLListBefore( myList, 18);

	printf("Mylist is: ");
	showDLList(myList);

	value = DLListCurrent(myList); 
	printf("Current value is %d.\n", value);

	DLListDelete(myList);
	value = DLListCurrent(myList); 
	printf("After deleting. Current value is %d.\n", value);

	DLListMoveTo(myList, 3);
	value = DLListCurrent(myList); 
	printf("Moving to position 3. Current value is %d.\n", value);

	printf("Deleting current value. Mylist is: ");
	DLListDelete(myList);
	showDLList(myList);

	int length = DLListLength(myList);
	printf("The length of mylist is: %d.\n", length);

	return 0;
}
