/**
 * @file main.c
 * @author Camus (abcamus_dev@163.com)
 * @brief 如何将一个递归程序转换成迭代形式
 * @version 0.1
 * @date 2022-05-05
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <assert.h>

/* 阶乘函数，返回n! */
int factorial(int n);

int factorial(int n)
{
    if (n == 1) {
        return n;
    }

    return n * factorial(n - 1);
}

int factorial_iter(int n)
{
    /* 第一步：定义状态，本例状态为factorial(n - 1)，是int型，初值是1 */
    int state = 1;
    /* 第二步：根据递归式确定迭代变量，从1迭代到n */
    for (int i = 1; i <= n; i++) {
        /* 第二步：实现每一步的状态改变 */
        state *= i;
    }

    return state;
}

struct LList {
    int val;
    struct LList *next;
};

void delete_linked_list(struct LList *head)
{
    if (head) {
        struct LList *next = head->next;
        free(head);
        delete_linked_list(next);
    }
}

void build_linked_list(struct LList *head, int num)
{
    struct LList *current = head;
    for (int i = 0; i < 10; i++) {
        current->next = (struct LList *)malloc(sizeof(struct LList));
        current = current->next;
        current->next = NULL;
    }
}

int main(int argc, char const *argv[])
{
    /* 第一个例子：阶乘 */
    printf("%d\n", factorial(10));
    assert(factorial(10) == factorial_iter(10));

    /* 第二个例子：删除链表 */
    struct LList head;
    build_linked_list(&head, 10);
    delete_linked_list(&head);

    return 0;
}
