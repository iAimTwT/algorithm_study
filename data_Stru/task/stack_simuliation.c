#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// 初始化栈
void initStack(Stack *stack) {
    stack->top = -1;
}

// 入栈操作
void push(Stack *stack, int value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("栈已满!\n");
        exit(1);
    }
    stack->data[++(stack->top)] = value;
}

// 出栈操作
int pop(Stack *stack) {
    if (stack->top == -1) {
        printf("栈已空!\n");
        exit(1);
    }
    return stack->data[(stack->top)--];
}

// 判断给定的出栈序列是否合法
int isCorrect(int n, int outOrder[]) {
    Stack stack;
    initStack(&stack);
    int i = 1, j = 0;
    while (i <= n) {
        push(&stack, i++);
        while (stack.top != -1 && stack.data[stack.top] == outOrder[j]) {
            pop(&stack);
            j++;
        }
    }
    return stack.top == -1;
}

int main() {
    int n;
    printf("请输入整数个数 n: ");
    scanf("%d", &n);
    
    int outOrder[MAX_SIZE];
    printf("请输入出栈顺序：");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &outOrder[i]);
    }

    if (isCorrect(n, outOrder)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    system("pause");
    return 0;
}
