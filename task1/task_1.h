#ifndef TASK1_H
#define TASK1_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COUNTRIES 12

/**
 * struct Country - Represents a country.
 * @name: The name of the country.
 * @borders: The indices of the neighboring countries.
 * @border_count: The number of neighboring countries.
 * @author: Frank Onyema Orji
 */
typedef struct Country
{
    char name[50];
    int borders[MAX_COUNTRIES];
    int border_count;
} Country;

/**
 * struct Graph - Represents a graph of countries.
 * @countries: An array of countries in the graph.
 * @country_count: The total number of countries in the graph.
 */
typedef struct Graph
{
    Country countries[MAX_COUNTRIES];
    int country_count;
} Graph;

/**
 * initializeGraph - Initializes the graph with given country names.
 * @graph: Pointer to the graph to be initialized.
 * @num_countries: The number of countries in the graph.
 * @country_names: Array of country names.
 */
void initializeGraph(Graph *graph, int num_countries, char country_names[][50])
{
    graph->country_count = num_countries;
    for (int i = 0; i < num_countries; i++)
    {
        strcpy(graph->countries[i].name, country_names[i]);
        graph->countries[i].border_count = 0;
        for (int j = 0; j < MAX_COUNTRIES; j++)
        {
            graph->countries[i].borders[j] = 0;
        }
    }
}

/**
 * addEdge - Creates a border (edge) between two countries.
 * @graph: Pointer to the graph.
 * @start: Index of the first country.
 * @end: Index of the second country.
 */
void addEdge(Graph *graph, int start, int end)
{
    graph->countries[start].borders[graph->countries[start].border_count++] = end;
    graph->countries[end].borders[graph->countries[end].border_count++] = start;
}

/**
 * printAdjacencyList - Prints the adjacency list representation of the graph.
 * @graph: Pointer to the graph.
 */
void printAdjacencyList(Graph *graph)
{
    for (int i = 0; i < graph->country_count; i++)
    {
        printf("%s: ", graph->countries[i].name);
        for (int j = 0; j < graph->countries[i].border_count; j++)
        {
            printf("%s ", graph->countries[graph->countries[i].borders[j]].name);
        }
        printf("\n");
    }
}

/**
 * printAdjacencyMatrix - Prints the adjacency matrix representation of the graph.
 * @graph: Pointer to the graph.
 */
void printAdjacencyMatrix(Graph *graph)
{
    for (int i = 0; i < graph->country_count; i++)
    {
        for (int j = 0; j < graph->country_count; j++)
        {
            int is_connected = 0;
            for (int k = 0; k < graph->countries[i].border_count; k++)
            {
                if (graph->countries[i].borders[k] == j)
                {
                    is_connected = 1;
                    break;
                }
            }
            printf("%d ", is_connected);
        }
        printf("\n");
    }
}

/**
 * deleteGraph - Frees the memory allocated for the graph.
 * @graph: Pointer to the graph to be deleted.
 */
void deleteGraph(Graph *graph)
{
    free(graph);
}

#endif /* TASK1_H */
