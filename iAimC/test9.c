#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode {
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BitTree;

#define MAX_TREE_SIZE 100

typedef struct {
    BitTree data[MAX_TREE_SIZE];
    int front;
    int rear;
} SqQueue;

void InitQueue(SqQueue *Q) {
    Q->rear = 0;
    Q->front = 0;
}

int QueueEmpty(SqQueue Q) {
    return Q.front == Q.rear;
}

void EnQueue(SqQueue *Q, BitTree bt) {
    if ((Q->rear + 1) % MAX_TREE_SIZE == Q->front) {
        fprintf(stderr, "队列已满\n");
        return;
    }
    Q->data[Q->rear] = bt;
    Q->rear = (Q->rear + 1) % MAX_TREE_SIZE;
}

void DeQueue(SqQueue *Q, BitTree *bt) {
    if (QueueEmpty(*Q)) {
        fprintf(stderr, "队列为空\n");
        return;
    }
    *bt = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAX_TREE_SIZE;
}

BitTree Pre_Create_BT() {
    char ch;
    ch = getchar();
    if (ch == '#') {
        return NULL;
    } else {
        BitTree bt = (BitTree)malloc(sizeof(BiTNode));
        if (bt == NULL) {
            fprintf(stderr, "内存分配失败\n");
            exit(EXIT_FAILURE);
        }
        bt->data = ch;
        bt->lchild = Pre_Create_BT();
        bt->rchild = Pre_Create_BT();
        return bt;
    }
}

void PreOrderTraverse(BitTree bt) {
    if (bt) {
        printf("%c ", bt->data);
        PreOrderTraverse(bt->lchild);
        PreOrderTraverse(bt->rchild);
    }
}

void InOrderTraverse(BitTree bt) {
    if (bt) {
        InOrderTraverse(bt->lchild);
        printf("%c ", bt->data);
        InOrderTraverse(bt->rchild);
    }
}

void PostOrderTraverse(BitTree bt) {
    if (bt) {
        PostOrderTraverse(bt->lchild);
        PostOrderTraverse(bt->rchild);
        printf("%c ", bt->data);
    }
}

void LayerOrder(BitTree bt) {
    if (!bt) return;
    SqQueue Q;
    InitQueue(&Q);
    EnQueue(&Q, bt);
    while (!QueueEmpty(Q)) {
        BitTree node;
        DeQueue(&Q, &node);
        printf("%c ", node->data);
        if (node->lchild) EnQueue(&Q, node->lchild);
        if (node->rchild) EnQueue(&Q, node->rchild);
    }
}

int main() {
    BitTree bt;
    printf("请按先序输入二叉树（用#表示空节点）：\n");
    bt = Pre_Create_BT();
    
    printf("先序遍历结果：");
    PreOrderTraverse(bt);
    printf("\n");

    printf("中序遍历结果：");
    InOrderTraverse(bt);
    printf("\n");

    printf("后序遍历结果：");
    PostOrderTraverse(bt);
    printf("\n");

    printf("层序遍历结果：");
    LayerOrder(bt);
    printf("\n");

    system("pause");
    return 0;
}
