# include <stdio.h>
# include "ADT/mesinkata/mesinkata.h"
# include "ADT/arrayuser/arrayuser.h"
# include "ADT/arrayitems/arrayitems.h"
// # include "ADT/mesinkata/mesinkata.c"
// # include "ADT/arrayuser/arrayuser.c"
// # include "ADT/mesinkarakter/mesinkarakter.c"
// # include "ADT/arrayitems/arrayitems.c"
// # include "ADT/mesinkarakter/mesinkarakter.c"
# include "load.c"

void Save (char * filename, ListofItems itemlist, ListofUsers userlist) {
  boolean success;
  WRITEFILE(filename,&success);
  printInt(Length(itemlist));
  int idx;
  for (int i = 0; i < Length(itemlist); i++) {
    printNewLine();
    printInt(Get(itemlist,i).price);
    // fprintf(pita,"%d",itemlist.A[i].price);
    printBlank();
    idx = 0;
    while (Get(itemlist,i).name[idx] != '\0') {
      printChar(Get(itemlist,i).name[idx]);
      // fprintf(pita,"%c",itemlist.A[i].name[idx]);
      idx++;
    }
  }
  // fprintf(pita,"\n");
  printNewLine();
  printInt(NbElmt(userlist));
  // fprintf(pita,"%d",userlist.Neff);
  for (int i = 0; i < NbElmt(userlist); i++) {
    // fprintf(pita,"\n");
    printNewLine();
    // fprintf(pita,"%d",userlist.TI[i].money);
    printInt(GetElmt(userlist,i).money);
    printBlank();
    // fprintf(pita," ");
    idx = 0;
    while (GetElmt(userlist,i).name[idx] != '\0') {
      printChar(GetElmt(userlist,i).name[idx]);
      // fprintf(pita,"%c",userlist.TI[i].name[idx]);
      idx++;
    }
    printBlank();
    // fprintf(pita," ");
    idx = 0;
    while (GetElmt(userlist,i).password[idx] != '\0') {
      printChar(GetElmt(userlist,i).password[idx]);
      // fprintf(pita,"%c",userlist.TI[i].password[idx]);
      idx++;
    }
  }
}

// int main () {
//   ListofItems items;
//   ListofUsers users;
//   items = MakeArrayDin();
//   MakeEmpty(&users);
//   Load("save2.txt",&items, &users);
//   Save("saveunyu.txt", items, users);
// }