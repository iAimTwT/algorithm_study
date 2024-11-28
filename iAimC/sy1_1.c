#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000

void bubble_sort(int arr[], int n) {
    for (int i = n; i > 0; i--) {
        for (int j = 1; j < i; j++) {
            if (arr[j - 1] > arr[j]) {
                int temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int data[N];
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        data[i] = rand(); // 产生随机数
    }

    // 冒泡排序
    int data1[N];
    for (int i = 0; i < N; i++) {
        data1[i] = data[i];
    }

    clock_t begin = clock(); // 记录开始排序前的时间
    bubble_sort(data1, N);
    clock_t end = clock(); // 排序结束后的时间
    printf("冒泡排序用时: %ld ms\n", (end - begin) * 1000 / CLOCKS_PER_SEC);


    getchar();
    return 0;
}