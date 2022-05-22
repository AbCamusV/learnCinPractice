#include <stdio.h>
#include "vector.h"

#define MAX_VEC_NUM 128

typedef struct {
    int data[MAX_VEC_NUM];
    int num;
} Vector;

static int vec_multiply(Vector *a, Vector *b)
{
    if (a->num != b->num) {
        return -1;
    }
    int res = 0;
    for (unsigned i = 0; i < a->num; i++) {
        res += a->data[i] * b->data[i];
    }

    return res;
}

int main(int argc, char **argv)
{
    Vector a = {
        .data = {0, 1, 2, 3},
        .num = 4,
    };

    Vector b = {
        .data = {1, 2, 3, 4},
        .num = 4,
    };

    int result = vec_multiply(&a, &b);
    printf("answer: %d\n", result);

    return 0;
}
