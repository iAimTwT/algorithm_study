#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct
{
    ElemType* data;
    int length;

} sqlist;

void createlist(sqlist* L) {
    L->data = (int*)malloc(sizeof(int));
    int k, a, n;
    printf("请输入顺序表的长度");
    scanf_s("%d", &n);
    L->length = n;
    printf("请输入%d个递减的整数", n);
    for (k = 0; k < n; k++) {
        scanf_s("%d", &a);
        L->data[k] = a;
    }
}

void outlist(sqlist* L) {
    printf("顺序表中的元素为：");
    int i;
    for (i = 0; i < L->length; i++)
    {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

// 合并两个有序顺序表并按递减顺序排列
void merge_lists(sqlist* L1, sqlist* L2, sqlist* merged) {
    int i = 0, j = 0, k = 0; // 初始化指针 i、j、k 分别指向 L1、L2、merged
    merged->length = L1->length + L2->length; // 合并后顺序表的长度
    merged->data = (ElemType*)malloc(merged->length * sizeof(ElemType)); // 分配存储空间

    // 循环比较两个顺序表的元素，按递减顺序放入合并后的顺序表中
    while (i < L1->length && j < L2->length) {
        if (L1->data[i] > L2->data[j]) {
            merged->data[k++] = L1->data[i++]; // 将 L1 的元素放入 merged
        } else {
            merged->data[k++] = L2->data[j++]; // 将 L2 的元素放入 merged
        }
    }

    // 将剩余元素拷贝进合并后的顺序表
    while (i < L1->length) {
        merged->data[k++] = L1->data[i++];
    }

    while (j < L2->length) {
        merged->data[k++] = L2->data[j++];
    }
}







int main()
{
    sqlist L1, L2, merged;
    printf("创建第一个顺序表:\n");
    createlist(&L1);
    printf("创建第二个顺序表:\n");
    createlist(&L2);

    printf("\n第一个顺序表:\n");
    outlist(&L1);
    printf("第二个顺序表:\n");
    outlist(&L2);

    merge_lists(&L1, &L2, &merged);
    printf("\n合并后的顺序表:\n");
    outlist(&merged);



    system("pause");
    return 0;
}