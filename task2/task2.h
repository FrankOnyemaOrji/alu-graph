#ifndef TASK2_H
#define TASK2_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VERTICES 9
#define MAX_EDGES_PER_VERTEX 4
#define QUEUE_SIZE 100

/**
 * struct Vertex - Represents a vertex in the graph.
 * @value: Integer value of the vertex.
 * @edges: Array of pointers to other vertices (edges).
 * @edgecount: Count of edges for this vertex.
 * @author: Frank Onyema Orji
 */
typedef struct Vertex
{
    int value;
    struct Vertex **edges;
    int edgeCount;
} Vertex;

/**
 * struct Graph2 - Represents a graph.
 * @vertices: Array of vertices in the graph.
 * @vertexCount: Count of vertices in the graph.
 */
typedef struct Graph2
{
    Vertex vertices[MAX_VERTICES + 1];
    int vertexCount;
} Graph2;

/**
 * initializeGraph2 - Initializes the graph structure.
 * @graph: Pointer to the graph to initialize.
 */
void initializeGraph2(Graph2 *graph)
{
    graph->vertexCount = 0;
}

/**
 * addVertex - Adds a vertex to the graph.
 * @graph: Pointer to the graph where the vertex will be added.
 * @value: The value of the new vertex.
 */
void addVertex(Graph2 *graph, int value)
{
    if (graph->vertexCount >= MAX_VERTICES)
    {
        printf("The graph is full, cannot add more vertices.\n");
        return;
    }

    // Check if a vertex with this value already exists
    for (int i = 0; i < graph->vertexCount; ++i)
    {
        if (graph->vertices[i].value == value)
        {
            printf("Vertex with value %d already exists.\n", value);
            return;
        }
    }

    // Add the new vertex to the graph
    graph->vertices[graph->vertexCount].value = value;
    graph->vertices[graph->vertexCount].edges = NULL;
    graph->vertices[graph->vertexCount].edgeCount = 0;
    graph->vertexCount++;
}

/**
 * addEdge2 - Creates an edge between two vertices in the graph.
 * @graph: The graph containing the vertices.
 * @fromValue: The value of the start vertex.
 * @toValue: The value of the end vertex.
 */
void addEdge2(Graph2 *graph, int fromValue, int toValue)
{
    Vertex *fromVertex = NULL;
    Vertex *toVertex = NULL;

    for (int i = 0; i < graph->vertexCount; ++i)
    {
        if (graph->vertices[i].value == fromValue)
        {
            fromVertex = &graph->vertices[i];
            break;
        }
    }

    for (int i = 0; i < graph->vertexCount; ++i)
    {
        if (graph->vertices[i].value == toValue)
        {
            toVertex = &graph->vertices[i];
            break;
        }
    }

    if (fromVertex == NULL || toVertex == NULL)
    {
        printf("One or both vertices not found.\n");
        return;
    }

    if (fromVertex->edges == NULL)
    {
        fromVertex->edges = (Vertex **)malloc(MAX_EDGES_PER_VERTEX * sizeof(Vertex *));
        fromVertex->edgeCount = 0;
    }

    fromVertex->edges[fromVertex->edgeCount++] = toVertex;
}

/**
 * DFSUtil - Utility function for performing DFS.
 * @graph: The graph on which DFS is being performed.
 * @vertex: The current vertex in DFS traversal.
 * @visited: Array to track visited vertices.
 */
void DFSUtil(Graph2 *graph, Vertex *vertex, bool visited[])
{
    printf("%d ", vertex->value);
    visited[vertex->value] = true;

    for (int i = 0; i < vertex->edgeCount; ++i)
    {
        Vertex *currentEdge = vertex->edges[i];

        if (!visited[currentEdge->value])
        {
            DFSUtil(graph, currentEdge, visited);
        }
    }
}

/**
 * depthFirstSearch - Performs depth-first search on the graph.
 * @graph: The graph to perform DFS on.
 */
void depthFirstSearch(Graph2 *graph)
{
    bool visited[MAX_VERTICES + 1] = {false};

    printf("DFS traversal: ");
    for (int i = 0; i < graph->vertexCount; i++)
    {
        if (!visited[graph->vertices[i].value])
        {
            DFSUtil(graph, &(graph->vertices[i]), visited);
        }
    }
    printf("\n");
}

/**
 * breadthFirstSearch - Performs breadth-first search on the graph.
 * @graph: The graph to perform BFS on.
 */
void breadthFirstSearch(Graph2 *graph)
{
    bool visited[MAX_VERTICES] = {false};
    int queue[QUEUE_SIZE];
    int front = 0, rear = -1;

    printf("BFS traversal: ");

    for (int i = 0; i < graph->vertexCount; i++)
    {
        if (!visited[graph->vertices[i].value])
        {
            int current = i;

            visited[graph->vertices[current].value] = true;
            printf("%d ", graph->vertices[current].value);

            for (int j = 0; j < graph->vertices[current].edgeCount; j++)
            {
                Vertex *currentEdge = graph->vertices[current].edges[j];
                int neighbor = currentEdge->value;

                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    printf("%d ", neighbor);
                    queue[++rear] = neighbor;
                }
            }

            while (front <= rear)
            {
                int frontVertex = queue[front++];
                for (int k = 0; k < graph->vertices[frontVertex].edgeCount; k++)
                {
                    Vertex *currentEdge = graph->vertices[frontVertex].edges[k];
                    int neighbor = currentEdge->value;

                    if (!visited[neighbor])
                    {
                        visited[neighbor] = true;
                        printf("%d ", neighbor);
                        queue[++rear] = neighbor;
                    }
                }
            }
        }
    }
    printf("\n");
}

/**
 * deleteGraph2 - Frees the memory allocated for the graph.
 * @graph: The graph to be deleted.
 */
void deleteGraph2(Graph2 *graph)
{
    for (int i = 0; i < graph->vertexCount; i++)
    {
        if (graph->vertices[i].edges != NULL)
        {
            free(graph->vertices[i].edges);
        }
    }
    graph->vertexCount = 0;
}

#endif /* TASK2_H */