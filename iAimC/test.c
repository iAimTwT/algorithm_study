#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000

void counting_sort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radix_sort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    for (int exp = 1; max / exp > 0; exp *= 10)
        counting_sort(arr, n, exp);
}

int main() {
    int data[N];
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        data[i] = rand(); // 产生随机数
    }

    // 基数排序
    int data1[N];
    for (int i = 0; i < N; i++) {
        data1[i] = data[i];
    }

    clock_t begin = clock();
     radix_sort(data1, N);
    clock_t end = clock();
    printf("基数排序用时: %ld ms\n", (end - begin) * 1000 / CLOCKS_PER_SEC);

    // for (int i = 0; i < N; i++) {
    //     printf("%d ",data1[i]);
    // }
    getchar();
    return 0;
}