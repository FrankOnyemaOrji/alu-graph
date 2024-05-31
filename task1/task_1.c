#include "task_1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Entry point.
 *
 * Return: Always 0.
 *@author: Frank Onyema Orji
 */
 * gcc -Wall -Wextra -Werror -pedantic -g3 -o task1 task1.c init.c
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

    Graph *g = malloc(sizeof(Graph));

    initializeGraph(g, MAX_COUNTRIES, country_names);

    /* TODO: loop */

    addEdge(g, 0, 1);  /*DRC Congo-Brazzaville*/
    addEdge(g, 1, 3);  /*DRC Rwanda*/
    addEdge(g, 1, 4);  /*DRC Burundi*/
    addEdge(g, 1, 6);  /*DRC Tanzania*/
    addEdge(g, 1, 7);  /*DRC Angola*/
    addEdge(g, 2, 6);  /*Uganda Tanzania*/
    addEdge(g, 2, 5);  /*Uganda Kenya*/
    addEdge(g, 3, 5);  /*Rwanda Tanzania*/
    addEdge(g, 4, 6);  /*Burundi Tanzania*/
    addEdge(g, 5, 6);  /*Kenya Tanzania*/
    addEdge(g, 6, 11); /*Tanzania Malawi*/
    addEdge(g, 6, 10); /*Tanzania Mozambique*/
    addEdge(g, 6, 8);  /*Tanzania Zambia*/
    addEdge(g, 7, 8);  /*Angola Zambia*/
    addEdge(g, 8, 11); /*Zambia Malawi*/
    addEdge(g, 8, 9);  /*Zambia Zimbabwe*/
    addEdge(g, 8, 9);  /*Zambia Mozambique*/
    addEdge(g, 9, 10); /*Zimbabwe Mozambique*/
    addEdge(g, 10, 6); /*Mozambique Tanzania*/

    printf("Adjacency list:\n");
    printAdjacencyList(g);

    printf("\nAdjacency matrix:\n");

    printAdjacencyMatrix(g);

    deleteGraph(g);

    return (0);
}