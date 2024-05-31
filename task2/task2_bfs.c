/*
* This program is a test driver for the breadth-first search function.
*/
#include "task2.h"

int main(void)
{
	Graph2 graph;

	initializeGraph2(&graph);

	for (int i = 1; i <= MAX_VERTICES; i++)
	{
		addVertex(&graph, i);
	}

	/*Vertex value 1 is connected to 4,3,5,8*/
	addEdge2(&graph, graph.vertices[0].value, graph.vertices[3].value);
	addEdge2(&graph, graph.vertices[0].value, graph.vertices[2].value);
	addEdge2(&graph, graph.vertices[0].value, graph.vertices[4].value);
	addEdge2(&graph, graph.vertices[0].value, graph.vertices[7].value);

	/*Vertex value 2 is connected to 8*/
	addEdge2(&graph, graph.vertices[1].value, graph.vertices[7].value);

	/*Vertex value 3 is connected to 7*/
	addEdge2(&graph, graph.vertices[2].value, graph.vertices[6].value);

	/*Vertex value 5 is connected to 1*, 6*/
	addEdge2(&graph, graph.vertices[4].value, graph.vertices[0].value);

	/*Vertex value 6 is connected to 9*/
	addEdge2(&graph, graph.vertices[5].value, graph.vertices[8].value);

	/*Vertex value 8 is connected to 2*/
	addEdge2(&graph, graph.vertices[7].value, graph.vertices[1].value);

	printf("Breadth-first search:\n");
	breadthFirstSearch(&graph);

	deleteGraph2(&graph);

	return (0);
}