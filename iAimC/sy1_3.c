#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000

void shell_sort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    int data[N];
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        data[i] = rand(); // 产生随机数
    }

 // 希尔排序
    int data1[N];
    for (int i = 0; i < N; i++) {
        data1[i] = data[i];
    }

    clock_t begin = clock();
    shell_sort(data1, N);
    clock_t end = clock();
    printf("希尔排序用时: %ld ms\n", (end - begin) * 1000 / CLOCKS_PER_SEC);


    getchar();
    return 0;
}