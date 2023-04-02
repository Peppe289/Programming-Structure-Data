#ifndef _PSD_ITEM_H_
#define _PSD_ITEM_H_

typedef void* Item;

Item inputItem();
void outputItem(Item);
int cmpItem(Item,Item);
Item addrDataInput(void);

#endif // _PSD_ITEM_H_