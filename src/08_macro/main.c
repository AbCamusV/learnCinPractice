#include <stdio.h>

#define MODULE_INIT(args, ...) init(__VA_ARGS__)

#define A_CMD "cmd"
#define Name(expand) A_##expand

void init(int a, int b) {
    printf("sum: %d\n", a+b);
}

int main(int argc, char const *argv[])
{
    printf("%s\n", Name(CMD));
    void (*callback)(int a, ...) = init;
    callback(1);

    return 0;
}