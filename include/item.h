#ifndef _PSD_ITEM_H_
#define _PSD_ITEM_H_

typedef void* Item;

#ifdef DEBUG
#define DBG(...)                      \
    do                                \
    {                                 \
        fprintf(stdout, __VA_ARGS__); \
    } while (0);
#else
#define DBG(...)
#endif

Item inputItem();
void outputItem(Item);
int cmpItem(Item, Item);

#endif /* _PSD_ITEM_H_ */