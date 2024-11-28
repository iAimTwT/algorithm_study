#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pi = i + 1;

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}
int main() {
    int data[N];
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        data[i] = rand(); // 产生随机数
    }

    // 快速排序
    int data1[N];
    for (int i = 0; i < N; i++) {
        data1[i] = data[i];
    }

    clock_t begin = clock();
    quick_sort(data1, 0, N - 1);
    clock_t end = clock();
    printf("快速排序用时: %ld ms\n", (end - begin) * 1000 / CLOCKS_PER_SEC);

    // for (int i = 0; i < N; i++) {
    //     printf("%d ",data1[i]);
    // }
    getchar();
    return 0;
}