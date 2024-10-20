#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define SElemType int

//定义
typedef struct {
    SElemType top1;
    SElemType top2;
    SElemType data[MAXSIZE];
} SqStack;

// 初始化
void InitStack(SqStack *S){
    S->top1 = -1;
    S->top2 = MAXSIZE;  
}

// 入栈
void Push1(SqStack *S, SElemType e){
    if(S->top1 + 1 == S->top2){
        printf("栈S1已经满了"); 
    }
    S->data[++S->top1] = e;
}
void Push2(SqStack *S, SElemType e) {
    if (S->top2 - 1 == S->top1) {
        printf("栈S2已经满了\n");
        return;
    }
    S->data[--S->top2] = e; 
}

// 出栈操作
void Pop1(SqStack *S, SElemType *e){
    if(S->top1 == -1){
        exit(1); 
    }
    *e = S->data[S->top1--];
}
void Pop2(SqStack *S, SElemType *e) {
    if (S->top2 == MAXSIZE) {
        exit(1); 
    }
    *e = S->data[S->top2++]; 
}

int main() {
    SqStack stack;
    SElemType e;
    InitStack(&stack);


    for (int i = 1; i <= 5; i++) {
        Push1(&stack, i);
        printf("%d入栈S1\n", i);
    }
    for (int i = 6; i <= 10; i++) {
        Push2(&stack, i);
        printf("%d入栈S2\n", i);
    }
    printf("\n");

    printf("s1出栈顺序为:");
    while (stack.top1 != -1) {
        Pop1(&stack, &e);
        printf("%d ", e);
    }
    printf("\n");
    printf("s2出栈顺序为:");
    while (stack.top2 != MAXSIZE) {
        Pop2(&stack, &e);
        printf("%d ", e);
    }


    return 0;
}
