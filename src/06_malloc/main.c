/**
 * @file main.c
 * @author Camus (abcamus_dev@163.com)
 * @brief 测试malloc
 * @version 0.1
 * @date 2022-05-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <malloc.h>

int main(int argc, char const *argv[])
{
    char *addr = malloc(1);
    uint64_t word0 = *(uint64_t *)(addr - 16);
    uint64_t word1 = *(uint64_t *)(addr - 8);
    printf("%ld, %ld\n", word0, word1);
    free(addr);

    return 0;
}
