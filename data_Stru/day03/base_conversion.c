#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct 
{
    int data[MAXSIZE];
    int top;
}Stack;

//初始化栈
void initStack(Stack *stack){
    stack->top = -1;
}

//判断栈空
int isEmpty(Stack *stack){
    return stack->top == -1;
}

//判断栈满
int isFull(Stack *stack){
    return stack->top == MAXSIZE - 1;
}

//入栈
void push(Stack *stack,int value){
    if(isFull(stack)){
        printf("栈已满");
        exit(1);
    }
    stack->top++;
    stack->data[stack->top] = value;
}

//出栈
int pop(Stack *stack){
    if(isEmpty(stack)){
        printf("栈为空");
        exit(1);
    }
    return stack->data[stack->top--];
}

//进制转换
void convert(int original,int scale){
    Stack stack;
    initStack(&stack);

    while (original > 0)
    {
        push(&stack,original % scale);
        original /= scale;
    }
    
    printf("转换后的值为:");
    while (!isEmpty(&stack))
    {
        printf("%x ",pop(&stack));
    }
    
}


int main(){
    int original;
    int scale;

    printf("输入要转换的数和进制:");
    scanf("%d %d",&original,&scale);

    convert(original,scale);
    system("pause");
    return 0;
}


