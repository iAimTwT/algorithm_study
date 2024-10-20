#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define SElemType int

//定义
typedef struct {
    SElemType* base;
    SElemType* top;
    int stacksize;
} SqStack;

// 初始化
int InitStack(SqStack* S) {
    S->base = (SElemType*)malloc(MAXSIZE * sizeof(SElemType));
    if (!S->base) {
        exit(1);
    }
    S->top = S->base;
    S->stacksize = MAXSIZE;
    return 0;
}

// 入栈
void Push(SqStack* S, SElemType e) {
    if (S->top - S->base == S->stacksize) {
        exit(1);
    }
    *(S->top)++ = e;
}

// 出栈操作
void Pop(SqStack* S, SElemType* e) {
    if (S->top == S->base) {
        exit(1);
    }
    *e = *--(S->top);
}



int main()
{
    SqStack S;
    SElemType e;
  
    InitStack(&S);
    int  b, c, m, k = 0;
    printf("请输入一个十进制数");
    scanf_s("%d", &b);
    printf("请输入要转换的进制数");
    scanf_s("%d", &c);
    while (b != 0)
    {
        Push(&S, b % c);
        b = b / c;
        k++;

    }
    printf("转化的%d进制数为:", c);
    for (int j = 0; j < k; j++)
    {
         Pop(&S,&e);
         printf("%d", e);
    }
   
    return 0;
}
