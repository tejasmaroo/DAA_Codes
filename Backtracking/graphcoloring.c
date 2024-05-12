#include <stdio.h>

// Maximum number of vertices
#define MAX_VERTICES 100

// Function prototypes
void colorGraph(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int colors);
void printSolution(int colorArr[], int vertices);

int main() {
    // Example graph represented as an adjacency matrix
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int vertices = 4; // Number of vertices
    int colors = 3; // Number of colors

    // Call the graph coloring algorithm
    colorGraph(graph, vertices, colors);

    return 0;
}

// A utility function to check if the current color assignment is safe for vertex v
int isSafe(int v, int graph[MAX_VERTICES][MAX_VERTICES], int colorArr[], int c, int vertices) {
    for (int i = 0; i < vertices; i++)
        if (graph[v][i] && c == colorArr[i])
            return 0;
    return 1;
}

// A recursive utility function to solve graph coloring problem
int graphColoringUtil(int graph[MAX_VERTICES][MAX_VERTICES], int m, int colorArr[], int v, int vertices) {
    // Base case: If all vertices are assigned a color then return true
    if (v == vertices)
        return 1;

    // Consider this vertex v and try different colors
    for (int c = 1; c <= m; c++) {
        // Check if assignment of color c to v is valid
        if (isSafe(v, graph, colorArr, c, vertices)) {
            colorArr[v] = c;

            // recur to assign colors to rest of the vertices
            if (graphColoringUtil(graph, m, colorArr, v + 1, vertices))
                return 1;

            // If assigning color c doesn't lead to a solution then remove it
            colorArr[v] = 0;
        }
    }

    // If no color can be assigned to this vertex then return false
    return 0;
}

// Main function to assign colors using graph coloring algorithm
void colorGraph(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int colors) {
    int colorArr[MAX_VERTICES];
    for (int i = 0; i < vertices; i++)
        colorArr[i] = 0;

    if (!graphColoringUtil(graph, colors, colorArr, 0, vertices))
        printf("Solution does not exist");
    else
        printSolution(colorArr, vertices);
}

// A utility function to print solution
void printSolution(int colorArr[], int vertices) {
    printf("Vertex colors:\n");
    for (int i = 0; i < vertices; i++)
        printf("Vertex %d -> Color %d\n", i, colorArr[i]);
}
