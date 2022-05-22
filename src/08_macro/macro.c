#include <stdio.h>

#define printDBL(exp) printf(#exp " = %d\n", exp)
#define NEW_OBJ(class, name) class __class_ ## _name

int test(int argc, char const *argv[])
{
    // printf(EVAL_EXPR(1+2));
    printDBL(1+2);
    NEW_OBJ(int, a);

    printf("1+2" " = %d\n", 1+2);

    return 0;
}
