# include <stdio.h>
# include "arrayuser.h"
# include "arrayuser.c"

int main() {
  ListofUser UserList;
  MakeEmpty(&UserList);
  User user;
  user.money = 5000;
  user.name[0] = 'a';
  user.name[1] = 'n';
  user.name[2] = 'o';
  user.name[3] = '\0';
  user.password[0] = 's';
  user.password[1] = 't';
  user.password[2] = 'i';
  user.password[3] = '\0';
  SetEl(&UserList,0,user);\
  User newuser;
  newuser.money = 3000;
  newuser.name[0] = 'w';
  newuser.name[1] = 'i';
  newuser.name[2] = 's';
  newuser.name[3] = 'a';
  newuser.name[4] = '\0';
  newuser.password[0] = '2';
  newuser.password[1] = '1';
  newuser.password[2] = '1';
  newuser.password[3] = '2';
  newuser.password[4] = '\0';
  SetEl(&UserList,1,newuser);
  printf("%d",UserList.Neff);
  for (int j = 0; j < UserList.Neff; j++) {
    printf("%d\n",UserList.TI[j].money);
    int i = 0;
    while (UserList.TI[j].name[i] != '\0') {
      printf("%c",UserList.TI[j].name[i]);
      i++;
    }
    printf("\n");
    i = 0;
    while (UserList.TI[j].password[i] != '\0') {
      printf("%c",UserList.TI[j].password[i]);
      i++;
    }
    printf("\n");
  }
}