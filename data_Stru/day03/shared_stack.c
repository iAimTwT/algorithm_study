#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct 
{
    int data[MAXSIZE];
    int top1;
    int top2;
}shared_stack;

//初始化
void initSharedStack(shared_stack *stack){
    stack->top1 = -1;
    stack->top2 = MAXSIZE;
}

//判断s1是否栈空
int isEmptyStack1(shared_stack *stack){
    return stack->top1 == -1;
}

//判断s2是否栈空
int isEmptyStack2(shared_stack *stack){
    return stack->top2 == MAXSIZE;
}

//判断s1是否栈满
int isFullStack1(shared_stack *stack){
    return stack->top1 + 1 == stack->top2; 
} 

//判断s2是否栈满
int isFullStack2(shared_stack *stack){
    return stack->top2 - 1 == stack->top1; 
}

//s1入栈
void pushStack1(shared_stack *stack,int value){
    if (isFullStack1(stack)) {
        printf("s1栈已满\n");
        exit(1);
    }
    stack->top1++;
    stack->data[stack->top1] = value;
}

//s2入栈
void pushStack2(shared_stack *stack,int value){
    if(isFullStack2(stack)){
        printf("栈s2已满\n");
        exit(1);
    }
    stack->top2--;
    stack->data[stack->top2] = value;
}

//s1出栈
int popStack1(shared_stack *stack){
    if (isEmptyStack1(stack))
    {
        printf("栈已空\n");
        exit(1);
    }
    return stack->data[stack->top1--];
}

//s2出栈
int popStack2(shared_stack *stack){
    if (isEmptyStack2(stack))
    {
        printf("栈已空\n");
        exit(1);
    }
    return stack->data[stack->top2++];
}

int main(){
    shared_stack stack;
    initSharedStack(&stack);
    
    
    for(int i = 1;i < 10;i++){
        pushStack1(&stack,i);
    }

    for (int i = 1; i < 15; i++)
    {
        pushStack2(&stack,i);
    }
    
    printf("s1中元素顺序为:");
    while (!isEmptyStack1(&stack))
    {
        printf(" %d",popStack1(&stack));
    }
    printf("\n");


    printf("s2中元素顺序为:");
    while (!isEmptyStack2(&stack))
    {
        printf(" %d",popStack2(&stack));
    }
    printf("\n");

    system("pause");
    return 0;
}