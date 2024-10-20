#include <stdio.h>
#include <stdlib.h>

// 顺序表结构定义
typedef struct {
    int *data;      
    int length;     
    int capacity;   
} SeqList;

// 初始化顺序表
void initList(SeqList *list, int capacity) {
    list->data = (int *)malloc(capacity * sizeof(int));
    list->length = 0;
    list->capacity = capacity;
}

// 向顺序表中添加元素
void append(SeqList *list, int element) {
    if (list->length < list->capacity) {
        list->data[list->length++] = element;
    } else {
        printf("表以满\n");
    }
}

// 顺序查找函数
int sequentialSearch(SeqList *list, int x) {
    for (int i = 0; i < list->length; i++) {
        if (list->data[i] == x) {
            return i; // 找到元素，返回其索引
        }
    }
    return -1; // 未找到元素，返回 -1
}

// 释放顺序表占用的内存
void freeList(SeqList *list) {
    free(list->data);
    list->data = NULL;
    list->length = 0;
    list->capacity = 0;
}

int main() {
    int capacity = 10; // 定义顺序表的容量
    SeqList list;
    initList(&list, capacity);

    // 向顺序表中添加元素
    append(&list, 4);
    append(&list, 2);
    append(&list, 3);
    append(&list, 7);
    append(&list, 10);
    append(&list, 1);
    append(&list, 5);

    int x = 7;
    int result = sequentialSearch(&list, x);

    if (result != -1) {
        printf("%d被找到,下标为:%d\n", x, result);
    } else {
        printf("%d不在表中\n", x);
    }

    // 释放顺序表占用的内存
    freeList(&list);
    system("pause");
    return 0;
}
