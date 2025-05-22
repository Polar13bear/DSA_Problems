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
void DFS_Matrix(int n, int graph[n][n], int start, int visited[]) {
    printf("%d ", start);
    visited[start] = 1;
    for (int v = 0; v < n; v++) {
        if (graph[start][v] != 0 && !visited[v]) {
            DFS_Matrix(n, graph, v, visited);
        }
    }
}
void DFS_List(AdjNode* adj[], int start, int visited[]) {
    printf("%d ", start);
    visited[start] = 1;
    for (AdjNode* curr = adj[start]; curr != NULL; curr = curr->next) {
        if (!visited[curr->vertex]) {
            DFS_List(adj, curr->vertex, visited);
        }
    }
}
int main() {
    int n, representation, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Choose graph representation:\n1. Adjacency Matrix\n2. Adjacency List\n");
    scanf("%d", &representation);
    printf("Enter start vertex for DFS: ");
    scanf("%d", &start);
    switch (representation) {
        case 1: {
            int graph[n][n];
            int visited[n];
            printf("Enter adjacency matrix (0 for no edge):\n");
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    scanf("%d", &graph[i][j]);

            for (int i = 0; i < n; i++)
                visited[i] = 0;
            printf("DFS traversal (Matrix): ");
            DFS_Matrix(n, graph, start, visited);
            printf("\n");
            break;
        }
        case 2: {
            AdjNode* adj[n];
            int visited[n];
            for (int i = 0; i < n; i++) {
                adj[i] = NULL;
                visited[i] = 0;
            }
            printf("Enter edges as (u v), enter -1 -1 to stop:\n");
            while (1) {
                int u, v;
                scanf("%d %d", &u, &v);
                if (u == -1 && v == -1) break;
                addEdgeList(adj, u, v);
                addEdgeList(adj, v, u);  // Assuming undirected graph
            }
            printf("DFS traversal (List): ");
            DFS_List(adj, start, visited);
            printf("\n");
            break;
        }
        default:
            printf("Invalid choice!\n");
    }
    return 0;
}
