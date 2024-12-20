#include <stdio.h>
#include "../ADT/linkedlist/linkedlist.h"
#include "../ADT/mesinkata/mesinkata.h"
#include "../ADT/arrayitems/arrayitems.h"

void WishlistAdd(infotype newitem,List * wishlist, ListofItems itemlist);

void WishlistShow(List Wishlist);

void WishlistRemoveByIndex(List *wishlist, int index);

void WishlistRemoveByName(List *wishlist);

void WishlistClear(List *wishlist);

void WishlistSwap(List *wishlist, int pos1, int pos2);
