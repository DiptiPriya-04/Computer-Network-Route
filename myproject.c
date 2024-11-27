#include <stdio.h>
#include <limits.h>
#define MAX 10
int graph[MAX][MAX], n;
// Function to find the minimum distance vertex
int minDistance(int dist[], int visited[]) {
 int min = INT_MAX, min_index;
 for (int v = 0; v < n; v++)
 if (!visited[v] && dist[v] <= min) {
 min = dist[v];
 min_index = v;
 }
 return min_index;
}
// Dijkstra's Algorithm for shortest path
void dijkstra(int src, int dest) {
 int dist[MAX], visited[MAX], parent[MAX];
 for (int i = 0; i < n; i++) {
 dist[i] = INT_MAX;
 visited[i] = 0;
 parent[i] = -1;
 }
 dist[src] = 0;
 for (int count = 0; count < n - 1; count++) {
 int u = minDistance(dist, visited);
 visited[u] = 1;
 for (int v = 0; v < n; v++)
 if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
 dist[u] + graph[u][v] < dist[v]) {
 dist[v] = dist[u] + graph[u][v];
 parent[v] = u;
 }
 }
 // Print the shortest path
 printf("Shortest path from %d to %d is: ", src, dest);
 int path[MAX], path_index = 0, v = dest;
 while (v != -1) {
 path[path_index++] = v;
 v = parent[v];
 }
 for (int i = path_index - 1; i >= 0; i--) {
 printf("%d ", path[i]);
 if (i != 0) printf("-> ");
 }
 printf("\nTotal cost: %d\n", dist[dest]);
}
int main() {
 int src, dest, edges, u, v, w;
 printf("Enter number of routers: ");
 scanf("%d", &n);
 printf("Enter number of edges: ");
 scanf("%d", &edges);
 // Initialize graph
 for (int i = 0; i < n; i++)
 for (int j = 0; j < n; j++)
 graph[i][j] = 0;
 // Input edges
 for (int i = 0; i < edges; i++) {
 printf("Enter edge (u, v) and weight: ");
 scanf("%d %d %d", &u, &v, &w);
 graph[u][v] = w;
 graph[v][u] = w;
 }
 printf("Enter source router: ");
 scanf("%d", &src);
 printf("Enter destination router: ");
 scanf("%d", &dest);
 dijkstra(src, dest);
 return 0;
}