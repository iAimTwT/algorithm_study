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

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

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

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bucket_sort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    int bucket_count = max / 10 + 1;
    int buckets[bucket_count][N];
    int bucket_sizes[bucket_count];

    for (int i = 0; i < bucket_count; i++)
        bucket_sizes[i] = 0;

    for (int i = 0; i < n; i++) {
        int bucket_index = arr[i] / 10;
        buckets[bucket_index][bucket_sizes[bucket_index]++] = arr[i];
    }

    for (int i = 0; i < bucket_count; i++) {
        if (bucket_sizes[i] > 0) {
            insertion_sort(buckets[i], bucket_sizes[i]);
        }
    }

    int index = 0;
    for (int i = 0; i < bucket_count; i++) {
        for (int j = 0; j < bucket_sizes[i]; j++) {
            arr[index++] = buckets[i][j];
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
    printf("bubble_sort: %ld ms\n", (end - begin) * 1000 / CLOCKS_PER_SEC);

    // 归并排序
    int data2[N];
    for (int i = 0; i < N; i++) {
        data2[i] = data[i];
    }

    begin = clock(); // 记录开始排序前的时间
    merge_sort(data2, 0, N - 1);
    end = clock(); // 排序结束后的时间
    printf("merge_sort: %ld ms\n", (end - begin) * 1000 / CLOCKS_PER_SEC);

    // 选择排序
    int data1[N];
    for (int i = 0; i < N; i++) {
        data1[i] = data[i];
    }

    clock_t begin = clock();
    selection_sort(data1, N);
    clock_t end = clock();
    printf("selection_sort: %ld ms\n", (end - begin) * 1000 / CLOCKS_PER_SEC);

    // 快速排序
    int data2[N];
    for (int i = 0; i < N; i++) {
        data2[i] = data[i];
    }

    begin = clock();
    quick_sort(data2, 0, N - 1);
    end = clock();
    printf("quick_sort: %ld ms\n", (end - begin) * 1000 / CLOCKS_PER_SEC);

    // 希尔排序
    int data3[N];
    for (int i = 0; i < N; i++) {
        data3[i] = data[i];
    }

    begin = clock();
    shell_sort(data3, N);
    end = clock();
    printf("shell_sort: %ld ms\n", (end - begin) * 1000 / CLOCKS_PER_SEC);

    // 基数排序
    int data4[N];
    for (int i = 0; i < N; i++) {
        data4[i] = data[i];
    }

    begin = clock();
    radix_sort(data4, N);
    end = clock();
    printf("radix_sort: %ld ms\n", (end - begin) * 1000 / CLOCKS_PER_SEC);

    // 桶排序
    int data5[N];
    for (int i = 0; i < N; i++) {
        data5[i] = data[i];
    }

    begin = clock();
    bucket_sort(data5, N);
    end = clock();
    printf("bucket_sort: %ld ms\n", (end - begin) * 1000 / CLOCKS_PER_SEC);

    return 0;
}
