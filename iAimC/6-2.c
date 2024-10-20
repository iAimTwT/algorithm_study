#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct List {
    int* data;
    int length;
} Sqlist;

int initsqlist(Sqlist* L) {
    L->data = (int*)malloc(MAXSIZE * sizeof(int));
    L->length = 0;
    return 0;
}

void inputlist(Sqlist* L, int a[], int n) {
    for (int i = 0; i < n; i++) {
        L->data[i] = a[i];
    }
    L->length = n;
}

void swap(Sqlist* L, int i, int j) {
    int temp = L->data[i];
    L->data[i] = L->data[j];
    L->data[j] = temp;
}

int partition(Sqlist* L, int low, int high)
{
    int pivotkey;
    pivotkey = L->data[low];
    while (low < high)
    {
        while (low < high && L->data[high] >= pivotkey)
            high--;
        swap(L, low,high);
        while (low < high && L->data[low] <= pivotkey)
            low++;
        swap(L, low,high);
    }
    return low;
}
void QSort(Sqlist* L, int low, int high)
{
    int pivot;
    if (low < high)
    {
        pivot = partition(L, low, high);
        QSort(L, low, pivot - 1);
        QSort(L, pivot + 1,high);
    }
}
void QuickSort(Sqlist* L)
{
    QSort(L,0, L->length-1);
}
int main() {
    int low=0,high=0,n = 9;
    int a[] = { 19, 1, 23, 14, 50, 20, 84, 27, 60, 15 };
    Sqlist L;
    initsqlist(&L);
    inputlist(&L, a, n);
    QuickSort(&L);

    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");

    free(L.data);


    return 0;
}
