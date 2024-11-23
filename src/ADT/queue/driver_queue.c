#include <stdio.h>
#include "queue.h"

int main()
{
    Queue q;
    char *t;
    CreateQueue(&q);

    printf("%d\n", length(q));

    enqueue(&q, "halohead");
    enqueue(&q, "halotengah");
    enqueue(&q, "halotail");
    printf("%s\n", HEAD(q));
    printf("%s\n", TAIL(q));
    printf("%d\n", length(q));

    dequeue(&q, &t);

    printf("%s\n", TAIL(q));
    printf("%d\n", length(q));
}