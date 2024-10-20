#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct List {
    int* data;
    int length;
} sqlist;

int initsqlist(sqlist* L) {
    L->data = (int*)malloc(MAXSIZE * sizeof(int));
    L->length = 0;
    return 0;
}

void inputlist(sqlist* L, int a[], int n) {
    for (int i = 0; i < n; i++) {
        L->data[i] = a[i];
    }
    L->length = n;
}

void Merge(int SR[], int TR[], int i, int m, int n) {
    int j, k, l;
    for (j = m + 1, k = i; i <= m && j <= n; k++) {
        if (SR[i] <= SR[j])
            TR[k] = SR[i++];
        else
            TR[k] = SR[j++];
    }
    if (i <= m)
        for (l = 0; l <= m - i; l++)
            TR[k + l] = SR[i + l];
    else
        for (l = 0; l <= n - j; l++)
            TR[k + l] = SR[j + l];
}

void MSort(int SR[], int TR1[], int s, int n) {
    int m;
    int TR2[MAXSIZE + 1];
    if (s == n)
        TR1[s] = SR[s];
    else {
        m = (s + n) / 2;
        MSort(SR, TR2, s, m);
        MSort(SR, TR2, m + 1, n);
        Merge(TR2, TR1, s, m, n);
    }
}

void MergeSort(sqlist *L) {
    MSort(L->data, L->data, 0, L->length - 1);
}

int main() {
    int n = 9;
    int a[] = { 19, 1, 23, 14, 50, 20, 84, 27, 60, 15 };
    sqlist L;

    initsqlist(&L);
    inputlist(&L, a, n);

    MergeSort(&L);

    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");

    free(L.data);


    return 0;
}
