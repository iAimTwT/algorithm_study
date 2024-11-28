#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000

void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int data[N];
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        data[i] = rand(); // 产生随机数
    }

 // 选择排序
    int data1[N];
    for (int i = 0; i < N; i++) {
        data1[i] = data[i];
    }

    clock_t begin = clock();
    selection_sort(data1, N);
    clock_t end = clock();
    printf("选择排序用时: %ld ms\n", (end - begin) * 1000 / CLOCKS_PER_SEC);


    getchar();
    return 0;
}