#include <stdio.h>
#include <stdlib.h>
#include "betforjobs.h"

int main()
{
    int totaltime;
    scanf("%d", &totaltime);

    struct answer_t otv;
    otv.norders = totaltime;
    otv.numbers = calloc(otv.norders, sizeof(int));

    struct order_t pom[5];

    for (int i = 0; i < 5; i++) {
        scanf("%d %d %d", &pom[i].number, &pom[i].deadline, &pom[i].cost);
    }

    otv = betforjobs(pom, 5, totaltime);

    for (int i = 0; i < totaltime; i++)
        printf("%d ", otv.numbers[i]);


    return 0;
}
