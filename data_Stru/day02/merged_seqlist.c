#include <stdio.h>
#include <stdlib.h>

//定义顺序表
typedef struct 
{
    int *data;
    int length;
}seq_list;

//创建顺序表并输入元素
void createseq_list(seq_list *L,int n){
    L->data = (int*)malloc(sizeof(int));
    for(int i = 0;i<n;i++){
        scanf("%d",&(L->data[i]));
    }
}

//输出顺序表
void outputlist(seq_list *L){
    int index = 0;
    while (index < L->length)
    {
        printf("%d ",L->data[index]);
        index++;
    }
    printf("\n");
}

//插入排序
void insertsort(seq_list *L){
      for (int i = 1; i < L->length; i++) {
        int temp = L->data[i]; // 从未排序部分取出一个元素
        int j = i - 1;
        // 在已排序部分找到合适的位置插入
        while (j >= 0 && L->data[j] < temp) {
            L->data[j + 1] = L->data[j];
            j--;
        }
        L->data[j + 1] = temp;
    }
    outputlist(L);
}

//合并顺序表
seq_list *merged_seqlist(seq_list *x,seq_list *y){
   // 分配合并后的顺序表所需的内存
    seq_list* z = (seq_list*)malloc(sizeof(seq_list));
    if (z == NULL) {
        // 内存分配失败
        return NULL;
    }

    // 分配足够的内存来容纳两个顺序表的元素
    z->data = (int*)malloc(sizeof(int) * (x->length + y->length));
    if (z->data == NULL) {
        // 内存分配失败
        free(z); // 释放已分配的内存
        return NULL;
    }

    // 合并两个顺序表的元素
    int i = 0, j = 0, k = 0;
    while (i < x->length && j < y->length) {
        if (x->data[i] < y->data[j]) {
            z->data[k++] = x->data[i++];
        } else {
            z->data[k++] = y->data[j++];
        }
    }

    // 处理剩余的元素
    while (i < x->length) {
        z->data[k++] = x->data[i++];
    }
    while (j < y->length) {
        z->data[k++] = y->data[j++];
    }

    // 设置合并后顺序表的长度
    z->length = k;

    return z;
}

//测试程序
void test_seqlist(){
    seq_list L1;
    seq_list L2;
    int n1,n2;

    printf("输入表L1中元素的个数:");
    scanf("%d",&n1);
    L1.length = n1;

    printf("向顺序表中输入%d个元素:",n1);
    createseq_list(&L1,n1);
    insertsort(&L1);

    printf("输入表L2中元素的个数:");
    scanf("%d",&n2);
    L2.length = n2;

    printf("向顺序表中输入%d个元素:",n2);
    createseq_list(&L2,n2);
    insertsort(&L2);

    seq_list *L3 = merged_seqlist(&L1,&L2);
    insertsort(L3);

    system("pause");
}

int main(){
    test_seqlist();
    return 0;
}