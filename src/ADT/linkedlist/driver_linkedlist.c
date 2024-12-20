#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main()
{
  List L;
  char *temp;
  temp = (char *)malloc(LINKEDLIST_MAX_LEN * sizeof(char));
  CreateEmptyLL(&L);

  PrintInfoLL(L);
  printf("\n");

  InsVLast(&L, "Test");
  InsVFirst(&L, "Test3");
  printf("isEmpty: %d\n", IsEmptyLL(L));
  PrintInfoLL(L);
  printf("\n");

  InsVFirst(&L, "Test2");
  PrintInfoLL(L);
  printf("\n");

  DelVFirst(&L, &temp);
  printf("deleted: %s\n", temp);
  PrintInfoLL(L);
  printf("\n");

  DelVLast(&L, &temp);
  printf("deleted: %s\n", temp);
  PrintInfoLL(L);
  printf("\n");

  DelVLast(&L, &temp);
  printf("deleted: %s\n", temp);
  PrintInfoLL(L);
  printf("\n");
  printf("isEmpty: %d\n", IsEmptyLL(L));

  InsVLast(&L, "Test");
  InsVLast(&L, "Test2");
  InsVLast(&L, "Test3");
  InsVLast(&L, "Test4");
  InsVLast(&L, "Test5");
  InsVLast(&L, "Test6");
  PrintInfoLL(L);
  printf("\n");



  address Ptemp = Search(L, "Test4");
  if (Ptemp != NilLL) {
    printf("%s\n", Info(Ptemp));
    DelP(&L, "Test4");
  } else {
    printf("gaada bro\n");
  }
  PrintInfoLL(L);
  printf("\n");

  Ptemp = AddrOfIdx(L, 2);
  if (Ptemp != NilLL) {
    printf("%s\n", Info(Ptemp));
    DelP(&L, Info(Ptemp));
  } else {
    printf("gaada bro\n");
  }
  PrintInfoLL(L);
  printf("\n");
}