#include <stdio.h>
#include <stdlib.h>

#define N 8

typedef struct {
    int row;
    int col;
} Position;

typedef struct {
    Position positions[N];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == N - 1;
}

void push(Stack *s, int row, int col) {
    if (!isFull(s)) {
        s->top++;
        s->positions[s->top].row = row;
        s->positions[s->top].col = col;
    } else {
        printf("栈满\n");
    }
}

Position pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->positions[s->top--];
    } else {
        printf("栈空\n");
        Position p = {-1, -1};
        return p;
    }
}

int isSafety(Stack *s,int row,int col){
    for(int i = 0;i<=s->top;i++){
        int r = s->positions[i].row;
        int c = s->positions[i].col;
        if(c == col||abs(r-row)==abs(c-col)){
            return 0;
        }
    }
    return 1;
}

void printSolution(Stack *s) {
    static int solutions = 0;
    solutions++;
    printf("Solution %d:\n", solutions);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int isQueen = 0;
            for (int k = 0; k <= s->top; k++) {
                if (s->positions[k].row == i && s->positions[k].col == j) {
                    isQueen = 1;
                    break;
                }
            }
            if (isQueen) {
                printf("Q ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void solveQueens() {
    Stack stack;
    initStack(&stack);

    int row = 0;
    int col = 0;

    while (row < N) {
        while (col < N) {
            if (isSafety(&stack, row, col)) {
                push(&stack, row, col);
                row++;
                col = 0;
                break;
            } else {
                col++;
            }
        }

        if (col == N) {  // 当前行没有找到安全位置
            if (isEmpty(&stack)) {  // 栈为空，说明没有解决方案，退出循环
                break;
            }
            Position p = pop(&stack);  // 回溯到上一行
            row = p.row;
            col = p.col + 1;
        }

        if (row == N) {  // 找到一个解决方案
            printSolution(&stack);
            Position p = pop(&stack);  // 回溯到上一行
            row = p.row;
            col = p.col + 1;
        }
    }
}


int main() {
    solveQueens();
    system("pause");
    return 0;
}
