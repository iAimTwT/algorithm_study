#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000
int getMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void countingSortForRadix(int arr[], int size, int exp) {
    int* output = (int*)malloc(size * sizeof(int));
    int count[10] = {0};

    for (int i = 0; i < size; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }

    free(output);
}

void radixSort(int arr[], int size) {
    int max = getMax(arr, size);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSortForRadix(arr, size, exp);
    }
}

int main() {
    int data[N];
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        data[i] = rand() % 1000000;  // 产生随机数，范围在0到999999
    }


    // 基数排序
    int data1[N];
    for (int i = 0; i < N; i++) {
        data1[i] = data[i];
    }
    int size = sizeof(data1) / sizeof(data1[0]);

    clock_t begin = clock();
    radixSort(data1, size);
    clock_t end = clock();
    printf("基数排序用时: %ld ms\n", (end - begin) * 1000 / CLOCKS_PER_SEC);

    // for (int i = 0; i < N; i++) {
    //     printf("%d ",data1[i]);
    // }
    getchar();
    return 0;
}
