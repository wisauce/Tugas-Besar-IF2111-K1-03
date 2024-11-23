#include "mesinkarakter.h"
#include "../boolean.h"
#include <stdio.h>

int main()
{
    // test start
    // START();
    // while (currentChar != MARK)
    // {
    //     printf("%c", currentChar);
    //     ADV();
    // }

    // testing startfile
    boolean read;
    STARTFILE("save1.txt", &read);
    printf("%d\n", read);
    while (currentChar != MARK)
    {
        printf("%c", currentChar);
        ADV();
    }
}