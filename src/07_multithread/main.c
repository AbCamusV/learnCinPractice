#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>
// #include <sys/syscall.h>

static int count = 0;

void *__thread1(void *args)
{
    while (true) {
        count++;
        // printf("tid: %d; count: %d\n", gettid(), count);
        /* 等待1秒 */
        sleep(1);
    }
}

#define THREAD_NUM 4

int main(int argc, char const *argv[])
{
    pthread_t pid1, pid2;

    for (int i = 0; i < THREAD_NUM; i++) {
        (void)pthread_create(&pid1, NULL, __thread1, NULL);
        (void)pthread_create(&pid2, NULL, __thread1, NULL);
    }

    /* body */

    for (int i = 0; i < THREAD_NUM; i++) {
        pthread_join(pid1, NULL);
        pthread_join(pid2, NULL);
    }

    return 0;
}
