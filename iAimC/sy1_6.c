#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000

void counting_sort(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int* count = (int*)calloc(max + 1, sizeof(int));

    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }

    free(count);
}

int main() {
    int data[N];
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        data[i] = rand(); // 产生随机数
    }

    // 计数排序
    int data1[N];
    for (int i = 0; i < N; i++) {
        data1[i] = data[i];
    }
    int size = sizeof(data1) / sizeof(data1[0]);


    clock_t begin = clock();
    counting_sort(data1, size);
    clock_t end = clock();
    printf("计数排序用时: %ld ms\n", (end - begin) * 1000 / CLOCKS_PER_SEC);

    // for (int i = 0; i < N; i++) {
    //     printf("%d ",data1[i]);
    // }
    getchar();
    return 0;
}