#include "item.h"

typedef struct list *List;

List newList();
int isEmpty(List);
void addHead(List, Item);
Item removeHead(List);
Item getHead(List);
int sizeList(List);
void printList(List); 
void sortList(List data);

Item searchListItem(List, Item, int *);
Item removeListItem(List, Item);
Item removeListPos(List, int);
int addListPos(List, Item, int);
int addListTail(List, Item);
void reverseList(List);
List cloneList(List);
List cloneListItem(List);
char *inputString();
struct node *headList(List data);
struct node *nextList(struct node *data);
Item valueNode(struct node *data);

