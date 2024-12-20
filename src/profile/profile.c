#include "profile.h"
#include "../console.h"
#include <stdio.h>

void Profile(ListofUsers userlist, int currentUserIndex)
{
    clearterminal();
    printf(".______   .______        ______    _______  __   __       _______ \n");
    printf("|   _  \\  |   _  \\      /  __  \\  |   ____||  | |  |     |   ____|\n");
    printf("|  |_)  | |  |_)  |    |  |  |  | |  |__   |  | |  |     |  |__   \n");
    printf("|   ___/  |      /     |  |  |  | |   __|  |  | |  |     |   __|  \n");
    printf("|  |      |  |\\  \\----.|  `--'  | |  |     |  | |  `----.|  |____ \n");
    printf("| _|      | _| `._____| \\______/  |__|     |__| |_______||_______|\n");
    printf("                                                                  \n");
    printf("\n");
    printf("Nama : %s\n", userlist.TI[currentUserIndex].name);
    printf("Saldo: %d\n", userlist.TI[currentUserIndex].money);
    printf("\n");
    
    return;
}