#ifndef TASK1_H
#define TASK1_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COUNTRIES 12

/**
* struct Country - A country.
* @name: The name of the country.
* @edges: The countries that this country shares a border with.
* @edge_count: The number of countries that this country shares a border with.
* @author: Frank Onyema Orji
*/
typedef struct Country
{
	char name[50];

	int edges[MAX_COUNTRIES];

	int edge_count;

} Country;

/**
* struct Graph - A graph.
* @countries: The countries in the graph.
* @country_count: The number of countries in the graph.
*/
typedef struct Graph
{
	Country countries[MAX_COUNTRIES];
	int country_count;

} Graph;

/*
* initializeGraph - Initializes the graph with the given country names.
* @g: The graph to initialize.
* @number_of_countries: The number of countries in the graph.
* @country_names: The names of the countries.
*/
void initializeGraph(Graph *g, int number_of_countries, char country_names[][50])
{
	g->country_count = number_of_countries;
	for (int i = 0; i < number_of_countries; i++)

	{
		strcpy(g->countries[i].name, country_names[i]);
		g->countries[i].edge_count = 0;
		for (int j = 0; j < MAX_COUNTRIES; j++)

		{
			g->countries[i].edges[j] = 0;
		}
	}
}

/*
* addEdge - Adds an edge between two countries.
* @g: The graph to add the edge to.
* @start: The index of the first country.
* @end: The index of the second country.
*/
void addEdge(Graph *g, int start, int end)
{
	g->countries[start].edges[g->countries[start].edge_count++] = end;
	g->countries[end].edges[g->countries[end].edge_count++] = start;
}

/*
* printAdjacencyList - Prints the adjacency list of the graph.
* @g: The graph to print.
*/
void printAdjacencyList(Graph *g)
{
	for (int i = 0; i < g->country_count; i++)

	{
		printf("%s: ", g->countries[i].name);
		for (int j = 0; j < g->countries[i].edge_count; ++j)

		{
			printf("%s ", g->countries[g->countries[i].edges[j]].name);
		}
		printf("\n");
	}
}

/*
 * printAdjacencyMatrix - Prints the adjacency matrix of the graph.
 * @g: The graph to print.
 */
void printAdjacencyMatrix(Graph *g)
{
	for (int i = 0; i < g->country_count; i++)

	{
		for (int j = 0; j < g->country_count; j++)

		{
			int connected = 0;

			for (int k = 0; k < g->countries[i].edge_count; k++)

			{
				if (g->countries[i].edges[k] == j)
				{
					connected = 1;
					break;
				}
			}

			printf("%d ", connected);
		}
		printf("\n");
	}
}

/*
* deleteGraph - Deletes the graph.
* @g: The graph to delete.
*/
void deleteGraph(Graph *g)
{
	free(g);
}

#endif /* TASK1_H */