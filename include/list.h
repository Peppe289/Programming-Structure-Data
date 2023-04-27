#ifndef _PSD_LIST_H_
#define _PSD_LIST_H_

#include <item.h>

#ifdef GDB_DEBUG
#include <signal.h>
#endif

typedef struct list *List;

List newList();
int isEmpty(List);
void addHead(List, Item);
Item removeHead(List);
Item getHead(List);
int sizeList(List);
//void printList(List); 
void sortList(List data);

Item searchListItem(List, Item, int *);
Item removeListItem(List, Item);
Item removeListPos(List, int);
char *inputString();
struct node *headList(List data);
struct node *nextList(struct node *data);
Item valueNode(struct node *data);
int addListPos(List list, Item el, int pos);
void reverseList(List list);
List clonelist(List list);
Item cloneDataArgs(Item data);

/**********************
 * Funzioni ricorsive *
 **********************/
void printListRec(List);
void destroyListRec(List);
int countItemListRec(List, Item);
Item searchListRec(List, Item, int *);

#endif // _PSD_LIST_H_