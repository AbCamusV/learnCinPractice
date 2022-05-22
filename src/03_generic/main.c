#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SWAP(a, b)      \
    do {                \
        int _temp = a;  \
        a = b;          \
        b = _temp;      \
    } while (0)

#define SWAP_GENERIC(a, b, size)        \
    do {                                \
        char _temp[128];               \
        memcpy(_temp, a, size);         \
        memcpy(a, b, size);             \
        memcpy(b, _temp, size);         \
    } while (0)

bool compare_ascend(int a, int b)
{
    return a > b;
}

bool compare_descend(int a, int b)
{
    return a < b;
}

typedef struct {
    char *name;
    int grade;
} Student;

/**
 * @brief 按照成绩从高到低排序，同样的成绩按照名字字典顺序排序
 *
 * @param _a
 * @param _b
 * @return true
 * @return false
 */
bool compare_ascend_generic(const void *_a, const void *_b)
{
    const Student *a = (const Student *)_a;
    const Student *b = (const Student *)_b;

    return (a->grade == b->grade && strcmp(a->name, b->name)) ||
           (a->grade < b->grade);
}

void bubble_sort3(void *data[], int size, int num, bool (*compare)(const void *, const void *))
{
    int i, j;
    for (i = 0; i < num; i++) {
        for (j = 0; j < num - i - 1; j++) {
            if (compare(data[j], data[j+1])) {
                SWAP_GENERIC(data[j], data[j+1], size);
            }
        }
    }
}

/**
 * @brief 能兼容递增和递减排序
 *
 * @param data
 * @param num
 * @param compare
 */
void bubble_sort2(int *data, int num, bool (*compare)(int, int))
{
    int i, j;
    for (i = 0; i < num; i++) {
        for (j = 0; j < num - i - 1; j++) {
            if (compare(data[j], data[j+1])) {
                SWAP(data[j], data[j+1]);
            }
        }
    }
}

void bubble_sort1(int *data, int num)
{
    int i, j;
    for (i = 0; i < num; i++) {
        for (j = 0; j < num - i - 1; j++) {
            if (data[j] > data[j+1]) {
                SWAP(data[j], data[j+1]);
            }
        }
    }
}

void bubble_sort(int *data, int num)
{
    int i, j;
    for (i = 0; i < num; i++) {
        for (j = 0; j < num - i - 1; j++) {
            if (data[j] > data[j+1]) {
                int temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
}

void print(Student *s)
{
    printf("grade : %d, name : %s\n", s->grade, s->name);
}

int main(int argc, char const *argv[])
{
    int array[128] = { 5, 4, 2, 1, 3};
    int num = 5;

    Student data[5] = {
        {
            .grade = 100,
            .name = "alice",
        },
        {
            .grade = 90,
            .name = "GGG",
        },
        {
            .grade = 90,
            .name = "FFF",
        }
    };

    Student *p[5] = {
        &data[0],
        &data[1],
        &data[2],
    };

    num = 3;

    // bubble_sort(array, num - 1);
    // bubble_sort1(array, num - 1);
    // bubble_sort2(array, num, compare_ascend);
    // bubble_sort2(array, num, compare_descend);
    bubble_sort3((void **)p, sizeof(Student), num, compare_ascend_generic);

    for (int i = 0; (i < num) || (printf("\n") && false); print(p[i]),i++);

    return 0;
}
