#include <stdio.h>
#include <stdlib.h>

#define MAX 5
#define VISITED 1
#define UNVISITED 0

typedef struct node {
    int vertex;           // neighbor vertex
    struct node* next;
} Node;

typedef struct {
    Node* adj[MAX];       // adjacency lists
} Graph;

typedef struct{
    int data[MAX];
    int front;
    int rear;
}Queue;

void initQueue(Queue *q){
    q->front = q->rear = -1;
}
    
int isEmpty(Queue *q){
    return q->front == -1;
}
    
int isFull(Queue *q){
    return q->rear == MAX-1;
}
    
void enqueue(Queue *q, int data){
    if(!isFull(q)){
        if(q->front == -1){
            q->front = 0;
        }
    q->data[++q->rear] = data;
    }
}
    
int dequeue(Queue *q){
    if(!isEmpty(q)){
        int data = q->data[q->front];
        q->front++;
        return data;
    }
}

Graph initialize() {
    Graph g;
    for (int i = 0; i < MAX; i++)
        g.adj[i] = NULL;
    return g;
}

void insert(Graph* g, int u, int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = g->adj[u];
    g->adj[u] = newNode;
}

void dfs(Graph* g, int vertex, int mark[]) {
    mark[vertex] = VISITED;
    printf("Visited %d\n", vertex);

    Node* trav = g->adj[vertex];
    while (trav != NULL) {
        int nV = trav->vertex;
        if (mark[nV] == UNVISITED)
            dfs(g, nV, mark);
        trav = trav->next;
    }
}

void bfs(Graph* g, int start){
    Queue q;
    initQueue(&q);
    
    int mark[MAX] = { UNVISITED };
    mark[start] = VISITED;
    enqueue(&q, start);
    while(!isEmpty(&q)){
        int v = dequeue(&q);
        printf("Visited %d\n", v);
        Node *trav = g->adj[v];
        while(trav!=NULL){
            int nV = trav->vertex;
            if(mark[nV] == UNVISITED){
                mark[nV] = VISITED;
                enqueue(&q, nV);
            }
            trav = trav->next;
        }
    }
}

void printGraph(Graph* g) {
    for (int i = 0; i < MAX; i++) {
        printf("Vertex %d: ", i);
        Node* trav = g->adj[i];
        while (trav != NULL) {
            printf("%d -> ", trav->vertex);
            trav = trav->next;
        }
        printf("NULL\n");
    }
}

int main() {
    Graph g = initialize();
    int mark[MAX] = { UNVISITED };

    // Build graph
    insert(&g, 0, 1);
    insert(&g, 0, 2);
    insert(&g, 1, 3);
    insert(&g, 2, 4);

    dfs(&g, 0, mark);
    printf("\n");
    bfs(&g, 0);
    printGraph(&g);

    return 0;
}