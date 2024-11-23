#ifndef _STORE_H
#define _STORE_H

#include "ADT/arrayitems/arrayitems.h"
#include "ADT/queue/queue.h"


void StoreList(ListofItems items);

void StoreRemove(ListofItems *items);

void StoreRequest(ListofItems *items, Queue *q);

void StoreSupply(ListofItems *items, Queue *q);

#endif