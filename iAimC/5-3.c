#include <stdio.h>
#include <stdlib.h>

#define HASHSIZE 13
#define NULLKEY -32678

typedef struct {
    int* elem; // 数据存储基址，动态分配地址
    int count; // 当前元素个数
} HashTable;

int m = 0;

int InitHashTable(HashTable* H) { // 初始化散列表
    int i;
    m = HASHSIZE;
    H->count = m;
    H->elem = (int*)malloc(m * sizeof(int));
    if (!H->elem) {
        printf("内存分配失败\n");
        return 0;
    }
    for (i = 0; i < m; i++) {
        H->elem[i] = NULLKEY;
    }
    return 1;
}

int Hash(int key) { // 散列函数
    return key % m;
}

void InsertHash(HashTable* H, int key) { // 插入关键字
    int ad = Hash(key);
    while (H->elem[ad] != NULLKEY) {
        ad = (ad + 1) % m;
    }
    H->elem[ad] = key;
}

void PrintHash(HashTable* H) {
    for (int i = 0; i < m; i++) {
        printf("%d ", H->elem[i]);
    }
}

int main() {
    int i, key, a[] = { 19, 1, 23, 14, 55, 20, 84, 27, 68, 15 };
    HashTable H;

    if (!InitHashTable(&H)) {
        return 1; // 初始化失败，退出程序
    }

    for (i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
        InsertHash(&H, a[i]);
    }

    PrintHash(&H);
    
   

    free(H.elem); // 释放内存
    return 0;
}
