// # include <stdio.h>
# include "ADT/mesinkata/mesinkata.h"
# include "ADT/arrayuser/arrayuser.h"
# include "ADT/arrayitems/arrayitems.h"
// # include "ADT/mesinkata/mesinkata.c"
// # include "ADT/arrayuser/arrayuser.c"
// # include "ADT/mesinkarakter/mesinkarakter.c"
// # include "ADT/arrayitems/arrayitems.c"

int WordtoInteger(Word word) {
  int sum = 0;
  for (int i = 0; i < word.Length; i++) {
    sum += (word.TabWord[i] - '0');
    sum *= 10;
  }
  sum/=10;
  return sum;
}

void Load(char * filename, ListofItems * itemlist, ListofUsers * userlist) {
  boolean success;
  int iteration;
  STARTFILE(filename,&success);
  CopyWord();
  iteration = WordtoInteger(currentWord);
  Item item;
  for (int i = 0; i < iteration; i++) {
    ADV();
    ADVWORD();
    item.price = WordtoInteger(currentWord);
    CopySentence();
    for (int j = 0; j < currentWord.Length; j++) {
      item.name[j] = currentWord.TabWord[j];
    }
    item.name[currentWord.Length] = '\0';
    InsertAt(itemlist,item,i);
  }
  ADV();
  CopyWord();
  iteration = WordtoInteger(currentWord);
  User user;
  for (int i = 0; i < iteration; i++) {
    ADV();
    ADVWORD();
    user.money = WordtoInteger(currentWord);
    ADVWORD();
    for (int j = 0; j < currentWord.Length; j++) {
      user.name[j] = currentWord.TabWord[j];
    }
    user.name[currentWord.Length] = '\0';
    ADVWORD();
    for (int j = 0; j < currentWord.Length; j++) {
      user.password[j] = currentWord.TabWord[j];
    }
    user.password[currentWord.Length] = '\0';
    SetEl(userlist,i,user);
  }
}

// int main() {
//   ListofItems itemlist;
//   ListofUsers userlist;
//   itemlist = MakeArrayDin();
//   MakeEmpty(&userlist);
//   char filename[100] = "save2.txt";
//   Load(filename, &itemlist, &userlist);
//   for (int i = 0; i < itemlist.Neff; i++) {
//     printf("%d ",itemlist.A[i].price);
//     int idx = 0;
//     while (itemlist.A[i].name[idx] != '\0') {
//       printf("%c",itemlist.A[i].name[idx]);
//       idx++;
//     }
//     printf("\n");
//   }
//   for (int i = 0; i < userlist.Neff; i++) {
//     printf("%d ",userlist.TI[i].money);
//     int idx = 0;
//     while (userlist.TI[i].name[idx] != '\0') {
//       printf("%c",userlist.TI[i].name[idx]);
//       idx++;
//     }
//     printf("\n");
//   }
// }