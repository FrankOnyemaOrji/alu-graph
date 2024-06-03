#include "task_1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Entry point of the program.
 *
 * Return: Always 0.
 * @author: Frank Onyema Orji
 */
 
int main(void)
{
    char country_names[MAX_COUNTRIES][50] = {
        "Congo-Brazzaville",
        "DRC",
        "Uganda",
        "Rwanda",
        "Burundi",
        "Kenya",
        "Tanzania",
        "Angola",
        "Zambia",
        "Zimbabwe",
        "Mozambique",
        "Malawi"};

    Graph *graph = malloc(sizeof(Graph));
    if (graph == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    initializeGraph(graph, MAX_COUNTRIES, country_names);

    addEdge(graph, 0, 1);  /* Congo-Brazzaville - DRC */
    addEdge(graph, 1, 3);  /* DRC - Rwanda */
    addEdge(graph, 1, 4);  /* DRC - Burundi */
    addEdge(graph, 1, 6);  /* DRC - Tanzania */
    addEdge(graph, 1, 7);  /* DRC - Angola */
    addEdge(graph, 2, 6);  /* Uganda - Tanzania */
    addEdge(graph, 2, 5);  /* Uganda - Kenya */
    addEdge(graph, 3, 5);  /* Rwanda - Kenya */
    addEdge(graph, 4, 6);  /* Burundi - Tanzania */
    addEdge(graph, 5, 6);  /* Kenya - Tanzania */
    addEdge(graph, 6, 11); /* Tanzania - Malawi */
    addEdge(graph, 6, 10); /* Tanzania - Mozambique */
    addEdge(graph, 6, 8);  /* Tanzania - Zambia */
    addEdge(graph, 7, 8);  /* Angola - Zambia */
    addEdge(graph, 8, 11); /* Zambia - Malawi */
    addEdge(graph, 8, 9);  /* Zambia - Zimbabwe */
    addEdge(graph, 8, 10); /* Zambia - Mozambique */
    addEdge(graph, 9, 10); /* Zimbabwe - Mozambique */
    addEdge(graph, 10, 6); /* Mozambique - Tanzania */

    printf("Adjacency List:\n");
    printAdjacencyList(graph);

    printf("\nAdjacency Matrix:\n");
    printAdjacencyMatrix(graph);

    deleteGraph(graph);

    return 0;
}
