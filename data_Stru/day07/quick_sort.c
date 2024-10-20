#include <stdio.h>
#include <stdlib.h>

//定义顺序表
typedef struct 
{
    int *data;
    int length;
} seq_list;

//创建顺序表并输入元素
void createseq_list(seq_list *L, int n){
    L->data = (int*)malloc(n * sizeof(int)); 
    L->length = n;
    for(int i = 0; i < n; i++){
        scanf("%d", &(L->data[i]));
    }
}

//输出顺序表
void outputlist(seq_list *L){
    int index = 0;
    while (index < L->length)
    {
        printf("%d ", L->data[index]);
        index++;
    }
    printf("\n");
}

//交换函数
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//分割函数
int partition(int L[], int low, int high) {
    int pivot = L[high];
    int i = low - 1;
    for(int j = low; j < high; j++) {
        if(L[j] <= pivot) {
            i++;
            swap(&L[i], &L[j]);
        }
    }
    swap(&L[i + 1], &L[high]);
    return i + 1;
}

//快速排序单元
void quicksortUnit(int L[], int low, int high) {
    if(low < high) {
        int pi = partition(L, low, high);
        quicksortUnit(L, low, pi - 1);
        quicksortUnit(L, pi + 1, high);
    }
}

//快速排序
void quicksort(seq_list *L) {
    quicksortUnit(L->data, 0, L->length - 1);
}

int main() {
    seq_list L;
    int n;
    printf("输入元素个数: ");
    scanf("%d", &n);

    printf("输入元素: ");
    createseq_list(&L, n);

    printf("排序前: ");
    outputlist(&L);

    quicksort(&L);

    printf("排序后: ");
    outputlist(&L);

    free(L.data); 
    system("pause");
    return 0;
}
