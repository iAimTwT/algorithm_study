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

//归并函数
void merge(int L[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *leftArr = (int *)malloc(n1 * sizeof(int));
    int *rightArr = (int *)malloc(n2 * sizeof(int));

    for(int i = 0; i < n1; i++)
        leftArr[i] = L[left + i];
    for(int j = 0; j < n2; j++)
        rightArr[j] = L[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2){
        if(leftArr[i] <= rightArr[j]){
            L[k] = leftArr[i];
            i++;
        } else {
            L[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        L[k] = leftArr[i];
        i++;
        k++;
    }

    while(j < n2){
        L[k] = rightArr[j];
        j++;
        k++;
    }

    free(leftArr);
    free(rightArr);
}

//归并排序单元
void mergesortUnit(int L[], int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;
        mergesortUnit(L, left, mid);
        mergesortUnit(L, mid + 1, right);
        merge(L, left, mid, right);
    }
}

//归并排序
void mergesort(seq_list *L){
    mergesortUnit(L->data, 0, L->length - 1);
}

int main(){
    seq_list L;
    int n;
    printf("输入元素个数: ");
    scanf("%d", &n);

    printf("输入元素: ");
    createseq_list(&L, n);

    printf("排序前: ");
    outputlist(&L);

    mergesort(&L);

    printf("排序后: ");
    outputlist(&L);

    free(L.data); 
    system("pause");
    return 0;
}
