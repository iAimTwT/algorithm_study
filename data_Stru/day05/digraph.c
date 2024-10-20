#include <stdio.h>
#include <stdlib.h>

// 图的顶点结构
typedef struct AdjListNode {
    int dest;
    struct AdjListNode* next;
} AdjListNode;

// 图的邻接表
typedef struct AdjList {
    AdjListNode* head;
} AdjList;

// 图结构
typedef struct Graph {
    int V;
    AdjList* array;
} Graph;

// 创建新的邻接表节点
AdjListNode* newAdjListNode(int dest) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// 创建图
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->array = (AdjList*)malloc(V * sizeof(AdjList));
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}

// 添加无向边
void addEdge(Graph* graph, int src, int dest) {
    // 添加从 src 到 dest 的边
    AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
    // 添加从 dest 到 src 的边
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// 深度优先搜索 (DFS)
void DFSUtil(Graph* graph, int v, int visited[]) {
    visited[v] = 1; // 设置当前顶点为已访问
    printf("%d ", v);
    AdjListNode* node = graph->array[v].head;
    while (node != NULL) {
        int adjVertex = node->dest;
        if (!visited[adjVertex]) // 如果邻接顶点未被访问，继续递归访问
            DFSUtil(graph, adjVertex, visited);
        node = node->next;
    }
}

void DFS(Graph* graph, int startVertex) {
    int* visited = (int*)malloc(graph->V * sizeof(int)); // 分配访问标志数组
    for (int i = 0; i < graph->V; ++i)
        visited[i] = 0; // 初始化所有顶点为未访问
    DFSUtil(graph, startVertex, visited);
    free(visited);
}

// 队列结构定义 (用于 BFS)
typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode *front, *rear;
} Queue;

// 创建空队列
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// 入队
void enqueue(Queue* queue, int data) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

// 出队
int dequeue(Queue* queue) {
    if (queue->front == NULL)
        return -1;
    QueueNode* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL)
        queue->rear = NULL;
    free(temp);
    return data;
}

// 检查队列是否为空
int isQueueEmpty(Queue* queue) {
    return queue->front == NULL;
}

// 广度优先搜索 (BFS)
void BFS(Graph* graph, int startVertex) {
    int* visited = (int*)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; ++i)
        visited[i] = 0;

    Queue* queue = createQueue();
    visited[startVertex] = 1;
    enqueue(queue, startVertex);

    while (!isQueueEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        AdjListNode* node = graph->array[currentVertex].head;
        while (node != NULL) {
            int adjVertex = node->dest;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                enqueue(queue, adjVertex);
            }
            node = node->next;
        }
    }

    free(visited);
    free(queue);
}

// 主函数测试 DFS 和 BFS
int main() {
    // 创建图
    int V = 5;
    Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printf("DFS 从0开始:\n");
    DFS(graph, 0);

    printf("\nBFS 从0开始:\n");
    BFS(graph, 0);

    system("pause");
    return 0;
}
