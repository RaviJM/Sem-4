#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define INF INT_MAX
#define V 4 // number of vertices

void printSolution(int dist[][V]) {
    printf("Shortest distances between all pairs of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                printf("INF ");
            }
            else{
                printf("%d   ", dist[i][j]);
            }
        }
        printf("\n");
    }
}




void floydWarshall(int graph[][V]) {

    int dist[V][V], i, j, k;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printSolution(dist);
}       




int main() {
    int graph[V][V], i, j;
    printf("Enter the graph in the form of an adjacency matrix of %d*%d:\n",V,V);
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++)  {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == -1) { // -1 indicates absence of edge between vertices i and j
                graph[i][j] = INF;
            }
        }
        printf("\n");
    }
    
    floydWarshall(graph);
    return 0;
}