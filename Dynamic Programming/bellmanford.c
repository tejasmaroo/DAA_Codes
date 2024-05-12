#include <stdio.h>
#include <limits.h>

// Number of vertices in the graph
#define V 5

// Function to find the minimum of two numbers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to implement the Bellman-Ford algorithm for finding the shortest paths from a single source vertex
void bellmanFord(int graph[V][V], int src) {
    // Create an array to store the distances from the source vertex to all other vertices
    int dist[V];

    // Initialize distances from source to all other vertices as INFINITY
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    // Distance from source vertex to itself is always 0
    dist[src] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        // Iterate through all edges
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                // Update distance to v if it is reachable through u and the distance to u plus the weight of the edge from u to v is less than the current distance to v
                if (graph[u][v] != 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                    dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Check for negative-weight cycles
    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            // If there is still a shorter path from u to v, then there is a negative-weight cycle
            if (graph[u][v] != 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                printf("Graph contains negative weight cycle\n");
                return;
            }
        }
    }

    // Print the shortest distances from the source vertex
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
    // Graph represented as adjacency matrix
    int graph[V][V] = {
        {0, -1, 4, 0, 0},
        {0, 0, 3, 2, 2},
        {0, 0, 0, 0, 0},
        {0, 1, 5, 0, 0},
        {0, 0, 0, -3, 0}
    };

    bellmanFord(graph, 0);

    return 0;
}
