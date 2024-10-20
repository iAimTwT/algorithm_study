# include <stdio.h>
# include <stdlib.h>
typedef struct List {
int* data;
int length;
}sqlist;
int initsqlist(sqlist* L) {
L->data = (int*)malloc(sizeof(int));
L->length = 0;
return 0;
}
void inputlist(sqlist* L, int a[], int n) {
for (int i = 0; i < n; i++) {
L->data[i] = a[i];
}

}

int main() {
int i=0, x, n = 7, low = 1, high = n, mid, a[] = { 4,1,6,8,5,3,0 };
int found = 0;
sqlist L;
initsqlist(&L);
inputlist(&L, a, n);
printf("请输入要查找的数字");
scanf_s("%d", &x);
while (low<= high){
mid = (low + high) / 2;
if (x == a[mid]) {
printf("%d", mid - 1);
found = 1;
}
if (x < a[mid]);
high = mid - 1;
if (x > a[mid]);
low = mid + 1;
if (x == a[i]) {
printf("%d", i);
found = 1;
}
i++;
}
if (found == 0)
printf("未找到该数字");
return 0;
}
