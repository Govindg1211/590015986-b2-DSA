#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// Structure to represent a graph
typedef struct {
    int numVertices;
    int numEdges;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Function to create a graph
Graph* createGraph(int numVertices, int numEdges) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->numEdges = numEdges;

    // Initialize adjacency matrix with zeros
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int source, int destination) {
    graph->adjacencyMatrix[source][destination] = 1;
    graph->adjacencyMatrix[destination][source] = 1; // For undirected graph
}

// Function to perform Breadth-First Search (BFS)
void bfs(Graph* graph, int source) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    visited[source] = 1;
    queue[rear++] = source;

    while (front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjacencyMatrix[vertex][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

// Function to perform Depth-First Search (DFS)
void dfs(Graph* graph, int source, int visited[MAX_VERTICES]) {
    visited[source] = 1;
    printf("%d ", source);

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjacencyMatrix[source][i] == 1 && visited[i] == 0) {
            dfs(graph, i, visited);
        }
    }
}

int main() {
    int numVertices, numEdges, source;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    Graph* graph = createGraph(numVertices, numEdges);

    printf("Enter the edges (start end):\n");
    
    // Input logic with validation
    for (int i = 0; i < numEdges; i++) {
        int start, end;
        printf("Input edge %d (start end): ", i + 1);
        scanf("%d %d", &start, &end);
        
        // Validate input vertices
        if (start < 0 || start >= numVertices || end < 0 || end >= numVertices) {
            printf("Invalid vertices. Please enter values between 0 and %d.\n", numVertices - 1);
            i--; // Decrement counter to repeat this iteration
            continue;
        }
        
        addEdge(graph, start, end);
    }

    printf("Enter the source vertex for traversal: ");
    scanf("%d", &source);

    // Validate source vertex
    if (source < 0 || source >= numVertices) {
        printf("Invalid source vertex. It must be between 0 and %d.\n", numVertices - 1);
        free(graph); // Free allocated memory before exit
        return -1;
    }

    printf("Breadth-First Search (BFS) traversal order: ");
    bfs(graph, source);
    printf("\n");

    printf("Depth-First Search (DFS) traversal order: ");
    int visited[MAX_VERTICES] = {0};
    dfs(graph, source, visited);
    printf("\n");

    free(graph); // Free allocated memory before exit
    return 0;
}