
#ifndef DLLIST_H
#define DLLIST_H

// External view of DLList
// Implementation given in DLList.c
// Implements a DLList of integers 

typedef struct DLListRep *DLList;

// 1. create a new empty DLList
DLList newDLList();

// 2. is the list empty?
int DLListIsEmpty(DLList);

// 3. return number of elements in a list
int DLListLength(DLList);

// 4. display items from a DLList, comma separated
void showDLList(DLList L);

// 5. free up all space associated with list
void freeDLList(DLList);

// 6. return item at current position
int DLListCurrent(DLList);

// 7. insert an item before current item
// new item becomes current item
void DLListBefore(DLList, int);

// 8. insert an item after current item
// new item becomes current item
void DLListAfter(DLList, int);

// 9. move current position (+ve forward, -ve backward)
// return 1 if reach end of list during move
int DLListMove(DLList, int);

// 10. move to specified position in list
// i'th node, assuming first node has i==1
int DLListMoveTo(DLList, int);

// 11. delete current item
// new item becomes item following current
// if current was last, current becomes new last
// if current was only item, current becomes null
void DLListDelete(DLList);

#endif





