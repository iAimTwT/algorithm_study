#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void backtrack(int* nums, int start, int end) {
    if (start == end) {
        for (int i = 0; i < end; i++) {
            printf("%d ", nums[i]);
        }
        printf("\n");
        return;
    }

    for (int i = start; i < end; i++) {
        int shouldSwap = 1;
        for (int j = start; j < i; j++) {
            if (nums[j] == nums[i]) {
                shouldSwap = 0;
                break;
            }
        }
        
        if (shouldSwap) {
            swap(&nums[start], &nums[i]);
            backtrack(nums, start + 1, end);
            swap(&nums[start], &nums[i]); // 回溯
        }
    }
}

int cmp(const int* a, const int* b) {
    return (*a - *b);
}

void perm(int* nums, int size) {
    qsort(nums, size, sizeof(int), (int (*)(const void*, const void*))cmp);
    backtrack(nums, 0, size);
}


int main() {
    int n;
    printf("请输入数组的大小: ");
    scanf("%d", &n);

    int* nums = (int*)malloc(n * sizeof(int));
    printf("请输入数组元素: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("所有唯一的全排列:\n");
    perm(nums, n);

    free(nums); 

    system("pause");
    return 0;
}
