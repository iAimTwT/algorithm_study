#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct
{
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
}Graph;

typedef struct 
{
    Graph *data[MAX_VERTICES];
    int front;
    int rear;
}Queue;
 
//队列初始化
void InitQueue(Queue *Q){
    Q->front = 0;
    Q->rear = 0;
}

int EmptyQueue(Queue *Q){
    return Q->front == Q->rear;
}

void EnQueue(Queue *Q,int value){
    Q->data[Q->rear++] = value;
}

int DeQueue(Queue *Q){
    return Q->data[Q->front++];
}

//初始化
void initGraph(Graph *G,int vertices){
    G->numVertices = vertices;
    for(int i=0;i<vertices;i++){
        for(int j = 0;j<vertices;j++){
            G->adjMatrix[i][j]=0;
        }
    }
}

//添加边
void addEdge(Graph *G,int source,int destination){
    G->adjMatrix[source][destination] = 1;
    G->adjMatrix[destination][source] = 1;
}

//DFS
void DFSUnit(Graph *G,int vertex,int visited[]){
    visited[vertex] = 1;
    printf("%d ",vertex);

    for(int i = 0;i<G->numVertices;i++){
        if(!visited[i]&&G->adjMatrix[vertex][i]==1){
            DFSUnit(G,i,visited);
        }
    }
}

void DFS(Graph *G,int startVertex){
    int visited[MAX_VERTICES]={0};
    DFSUnit(G,startVertex,visited);
}


//BFS
void BFS(Graph *G,int startVertex){
    int visited[MAX_VERTICES]={1};
    Queue q;
    InitQueue(&q);
    EnQueue(&q,startVertex);

    while (!EmptyQueue(&q))
    {
        int curVertex = DeQueue(&q);
        printf("%d ",curVertex);

        for(int i = 0;i<G->numVertices;i++){
            if(G->adjMatrix[curVertex][i]==1&& !visited[i]){
                visited[i]=1;
                EnQueue(&q,i);
            }
        }
    }
    
}

int main(){
    Graph g;
    initGraph(&g, 6);
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 2, 4);
    addEdge(&g, 3, 4);
    addEdge(&g, 3, 5);

    DFS(&g,0);
    printf("\n");
    BFS(&g,0);

    system("pause");
    return 0;
}
