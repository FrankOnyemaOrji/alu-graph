/*
 * This program demonstrates a test driver for the breadth-first search (BFS) algorithm.
 *@author: Frank Onyema Orji
 */
#include "task2.h"

int main(void)
{
	Graph2 graph;

	// Initialize the graph structure
	initializeGraph2(&graph);

	// Add vertices to the graph
	for (int i = 1; i <= MAX_VERTICES; i++)
	{
		addVertex(&graph, i);
	}

	// Define connections for vertex 1 (connected to vertices 4, 3, 5, and 8)
	addEdge2(&graph, graph.vertices[0].value, graph.vertices[3].value);
	addEdge2(&graph, graph.vertices[0].value, graph.vertices[2].value);
	addEdge2(&graph, graph.vertices[0].value, graph.vertices[4].value);
	addEdge2(&graph, graph.vertices[0].value, graph.vertices[7].value);

	// Define connection for vertex 2 (connected to vertex 8)
	addEdge2(&graph, graph.vertices[1].value, graph.vertices[7].value);

	// Define connection for vertex 3 (connected to vertex 7)
	addEdge2(&graph, graph.vertices[2].value, graph.vertices[6].value);

	// Define connections for vertex 5 (connected to vertices 1 and 6)
	addEdge2(&graph, graph.vertices[4].value, graph.vertices[0].value);
	addEdge2(&graph, graph.vertices[4].value, graph.vertices[5].value);

	// Define connection for vertex 6 (connected to vertex 9)
	addEdge2(&graph, graph.vertices[5].value, graph.vertices[8].value);

	// Define connection for vertex 8 (connected to vertex 2)
	addEdge2(&graph, graph.vertices[7].value, graph.vertices[1].value);

	// Perform breadth-first search and display the result
	printf("Breadth-First Search Result:\n");
	breadthFirstSearch(&graph);

	// Clean up and free the graph resources
	deleteGraph2(&graph);

	return 0;
}
