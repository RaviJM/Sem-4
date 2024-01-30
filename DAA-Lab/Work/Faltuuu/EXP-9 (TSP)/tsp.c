#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_N 20
int n;
int dist[MAX_N][MAX_N];
int visited[MAX_N];
int best_tour[MAX_N];
int best_cost = INT_MAX;

void branch_and_bound(int depth, int current_cost, int current_tour[]){
    // Check if the current tour is complete
    if (depth == n){
        // Check if the current tour is better than the best tour found so far
        if (current_cost + dist[current_tour[n - 1]][current_tour[0]] < best_cost){
            best_cost = current_cost + dist[current_tour[n - 1]][current_tour[0]];
            for (int i = 0; i < n; i++){
                best_tour[i] = current_tour[i];
            }
        }
        return;
    }
    // Find the minimum cost edge from the current node
    int min_cost = INT_MAX;
    int min_edge = -1;
    for (int i = 0; i < n; i++){
        if (!visited[i] && dist[current_tour[depth - 1]][i] < min_cost){

            min_cost = dist[current_tour[depth - 1]][i];
            min_edge = i;
        }
    }
    // Try all possible paths from the current node
    for (int i = 0; i < n; i++){
        if (!visited[i]){
            int new_cost = current_cost + dist[current_tour[depth - 1]][i];
            if (new_cost + min_cost < best_cost){
                visited[i] = 1;
                current_tour[depth] = i;
                branch_and_bound(depth + 1, new_cost, current_tour);
                visited[i] = 0;
            }
        }
    }
}

int main(){
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    printf("Enter the distances between each pair of cities:\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &dist[i][j]);
        }
    }
    int current_tour[MAX_N];
    current_tour[0] = 0;
    visited[0] = 1;
    branch_and_bound(1, 0, current_tour);
    printf("Tour: ");
    for (int i = 0; i < n; i++){
        printf("%d ", best_tour[i]);
    }
    printf("\n");
    printf("Cost: %d\n", best_cost);
    return 0;
}