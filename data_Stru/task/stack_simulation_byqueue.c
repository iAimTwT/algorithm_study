#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// 定义队列结构
typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

// 初始化队列
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

// 入队操作
void enqueue(Queue *q, int x) {
    if ((q->rear + 1) % MAX_SIZE ==  MAX_SIZE - 1) {
        printf("队列已满\n");
        exit(1);
    }
    q->data[q->rear] = x;
    q->rear = (q->rear + 1) % MAX_SIZE;
}

// 出队操作
int dequeue(Queue *q) {
    if (q->front == q->rear) {
        printf("队列已空\n");
        exit(1);
    }
    int x = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    return x;
}

// 判断出栈顺序是否正确
int isCorrectOrder(int n, int *order) {
    Queue q;
    initQueue(&q);
    int expected = 1; 
    for (int i = 0; i < n; i++) {
        while (q.rear == q.front || q.data[q.front] != order[i]) {
            if (expected > n) {
                return 0; 
            }
            enqueue(&q, expected);
            expected++;
        }
        dequeue(&q); 
    }
    return 1;
}

int main() {
    int n;
    printf("输入一个整数n(栈内是1-n 之间的 n 个整数): ");
    scanf("%d", &n);

    int order[MAX_SIZE];
    printf("输入栈的出栈顺序: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &order[i]);
    }

    if (isCorrectOrder(n, order)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    system("pause");
    return 0;
}
