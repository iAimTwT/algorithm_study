# include <stdio.h>
# include <stdlib.h>
#define ListSize 101
typedef struct List {
int* data;
int length;
int listsize;
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
int i, x, n = 7, a[] = { 0,2,3,4,6,8,9 };
int found = 0;
sqlist L;
initsqlist(&L);
inputlist(&L, a, n);
printf("请输入要查找的数字");
scanf_s("%d", &x);
for (i = 0; i < n; i++) {
if (L.data[i] == x) {
printf("%d", i);
found = 1;
}
}
if (found == 0)
printf("未找到该数字");
return 0;
}
