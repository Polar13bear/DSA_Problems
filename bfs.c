#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct AdjNode {
    int vertex;
    struct AdjNode* next;
} AdjNode;
void addEdgeList(AdjNode* adj[], int u, int v) {
    AdjNode* newNode = (AdjNode*)malloc(sizeof(AdjNode));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}
void BFS_Matrix(int n, int graph[n][n], int start) {
    int visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0;
    int queue[MAX], front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = 1;
    printf("BFS traversal (Matrix): ");
    while (front != rear) {
        int u = queue[front++];
        printf("%d ", u);
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && !visited[v]) {
                queue[rear++] = v;
                visited[v] = 1;
            }
        }
    }
    printf("\n");
}
void BFS_List(AdjNode* adj[], int n, int start) {
    int visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0;
    int queue[MAX], front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = 1;
    printf("BFS traversal (List): ");
    while (front != rear) {
        int u = queue[front++];
        printf("%d ", u);
        for (AdjNode* curr = adj[u]; curr != NULL; curr = curr->next) {
            int v = curr->vertex;
            if (!visited[v]) {
                queue[rear++] = v;
                visited[v] = 1;
            }
        }
    }
    printf("\n");
}
int main() {
    int n, representation, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Choose graph representation:\n1. Adjacency Matrix\n2. Adjacency List\n");
    scanf("%d", &representation);
    printf("Enter start vertex for BFS: ");
    scanf("%d", &start);
    switch (representation) {
        case 1: {
            int graph[n][n];
            printf("Enter adjacency matrix (0 for no edge):\n");
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    scanf("%d", &graph[i][j]);
            BFS_Matrix(n, graph, start);
            break;
        }
        case 2: {
            AdjNode* adj[n];
            for (int i = 0; i < n; i++)
                adj[i] = NULL;
            printf("Enter edges as (u v), enter -1 -1 to stop:\n");
            while (1) {
                int u, v;
                scanf("%d %d", &u, &v);
                if (u == -1 && v == -1) break;
                addEdgeList(adj, u, v);
                addEdgeList(adj, v, u);  // Assuming undirected graph
            }
            BFS_List(adj, n, start);
            break;
        }
        default:
            printf("Invalid choice!\n");
    }
    return 0;
}
