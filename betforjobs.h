#pragma once

// описание заказа
struct order_t {
    int number;
    int cost;
    int deadline;
};

// массив номеров выбранных заказов и его размер
struct answer_t {
    int norders;
    int *numbers;
};

typedef int (*cmp_t)(void const *lhs, void const *rhs);

int cmp_struct(const void *lhs, const void *rhs);

void *swap(void *parr, int nsorted, int min_ind, int eltsize);

int selstep(void *parr, int eltsize, int numelts, int nsorted, cmp_t cmp);

int sort_profit(struct order_t *orders, int n, cmp_t cmp);

struct answer_t betforjobs(struct order_t *orders, int n, int totaltime);
