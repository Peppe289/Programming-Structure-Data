#ifndef _PSD_ITEM_H_
#define _PSD_ITEM_H_

typedef void* Item;
typedef struct node *Node;

Item inputItem();
void outputItem(Item);
int cmpItem(Item,Item);
Item addrDataInput(void);
// void *addrStruct(Node data);
void free_struct(Node data);

#endif // _PSD_ITEM_H_