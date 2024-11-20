#include <stdio.h>
#include "arrayitems.h"

int main()
{
    ListofItems ItemList;
    ItemList = MakeArrayDin();
    Item item;
    item.price = 7500;
    item.name[0] = 'j';
    item.name[1] = 'o';
    item.name[2] = 'e';
    item.name[3] = '\0';
    InsertLast(&ItemList, item);
    item.price = 99999;
    item.name[0] = 'l';
    item.name[1] = 'e';
    item.name[2] = 'o';
    item.name[3] = 'n';
    item.name[4] = 'a';
    item.name[5] = '\0';
    InsertLast(&ItemList, item);
    printf("%d", Get(ItemList, 0).price);
    int idx = 0;
    while (Get(ItemList, 1).name[idx] != '\0')
    {
        printf("%c", Get(ItemList, 1).name[idx]);
        idx++;
    }
    printf("%d", Get(ItemList, 1).price);
}