#include <stdio.h>
#include <stdlib.h>
#include "betforjobs.h"

int cmp_struct(const void *lhs, const void *rhs)
{
    int const *lhsi = (int const *) lhs + 1;
    int const *rhsi = (int const *) rhs + 1;
    if (*lhsi <= *rhsi)
        return 1;
    else
        return 0;
}

void *swap(void *parr, int nsorted, int min_ind, int eltsize)
{
    char *p = calloc(eltsize, sizeof(char));
    char *p1 = parr + min_ind * eltsize;
    char *p2 = parr + nsorted * eltsize;
    for (int i = 0; i < eltsize; i++) {
        p[i] = p1[i];
        p1[i] = p2[i];
        p2[i] = p[i];

    }
    return NULL;
}

int selstep(void *parr, int eltsize, int numelts, int nsorted, cmp_t cmp)
{
    char *min = calloc(eltsize, sizeof(char));
    int min_ind, comp;
    char *p1 = parr;
    char *p2 = parr + nsorted * eltsize;

    if (nsorted < numelts) {
        for (int i = 0; i < eltsize; i++) {
            min[i] = p2[i];
        }
        min_ind = nsorted;
    } else
        return -1;


    for (int i = nsorted + 1; i < numelts; i++) {
        p1 = parr + i * eltsize;
        comp = cmp((const void *) p1, (const void *) min);
        if (comp > 0) {
            for (int j = 0; j < eltsize; j++) {
                min[j] = p1[j];
            }
            min_ind = i;
        }

    }
    swap(parr, nsorted, min_ind, eltsize);

    return 0;
}

int sort_profit(struct order_t *orders, int n, cmp_t cmp)
{
    for (int i = 0; i < n; i++)
        selstep((void *) orders, sizeof(*orders), n, i, cmp);

    //for (int i = 0; i < n; i++)
    //printf("%d ", orders[i]. number);
    //printf("\n");  
    return 0;
}

struct answer_t betforjobs(struct order_t *orders, int n, int totaltime)
{
    struct answer_t res;
    int pom[100000];
    for (int i = 1; i <= n; i++)
        pom[i - 1] = i;

    res.norders = totaltime;
    res.numbers = calloc(res.norders, sizeof(int));
    sort_profit(orders, n, cmp_struct);

    for (int j = totaltime; j > 0; j--) {
        for (int g = n - 1; g >= 0; g--) {
            if ((orders[g].deadline >= j)
                && (pom[orders[g].number - 1] != 0)) {
                res.numbers[j - 1] = orders[g].number;
                pom[orders[g].number - 1] = 0;
                break;
            }
        }
    }
    return res;
}