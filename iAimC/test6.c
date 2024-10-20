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

//按序插入
void insertlist(sqlist *L,int x) {
    int index = 0;
    for (int i = 0; x < L->data[i]; i++) {
        index = i+1;
    }
    L->length++;
    for (int i = L->length; i >index; i--) {
        L->data[i] = L->data[i - 1];
    }
    L->data[index] = x;
    outlist(L);
}

//查找
int searchlist(sqlist*L,int y) {
    int index = -1;
    for (int i = 0; i != L->length; i++) {
        if (L->data[i] == y) {
            index = i + 1;
        }
    }
    return index;
}

//删除元素
void dellist(sqlist* L, int i) {
    for (int j = i-1; j < L->length; j++) {
        L->data[j] = L->data[j + 1];
    }
    L->length--;
    outlist(L);
}

int main()
{
    int x, y ,n,i;
    sqlist L;
    createlist(&L);
    outlist(&L);

    printf("输入要插入的值：");
    scanf_s("%d", &x);
    insertlist(&L, x);
    
    printf("输入要查询的值: ");
    scanf_s("%d", &y);
    printf("该值的位置为：%d\n", searchlist(&L, y));

    printf("输入要删除的位置:");
    scanf_s("%d", &i);
    dellist(&L,i);

    system("pause");
    return 0;
}