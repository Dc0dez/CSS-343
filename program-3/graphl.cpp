// ------------------------------------------------ graphl.cpp --------------------------------------------------------

// Dylan Nelson CSS 343 A

// Creation Date
// 11/3/24

// Date of Last Modification
// 11/9/24

// ---------------------------------------------------------------------------------------------------------------------

// File implements declared methods in graphl.h 

// --------------------------------------------------------------------------------------------------------------------- 

// File is expected to implement methods and functions from graphl.h to create a weighted directed graph 
//      using an adjacency list 
//
// Used special algorithm "Depth First Search Algorithm" to display each node in depth-first order

// ---------------------------------------------------------------------------------------------------------------------

#include "graphl.h"

// ------------------------------------GraphL----------------------------------------------------- 

// Graphl: constructs graphl

// preconditions: assumes constructor will run when object is initialized 

// postconditions: if object is initialized, initializes nodeArray to empty

// -----------------------------------------------------------------------------------------------

GraphL::GraphL() : size(100) {
	nodeArray = new GraphNode[size+1];

	for (int i = 1; i <= size; ++i) {
		nodeArray[i] = {nullptr, "", false};
	}
}

// ------------------------------------~GraphL----------------------------------------------------- 

// ~GraphL: deletes nodeArray, deallocates all memory used

// preconditions: a valid graph is intialized  

// postconditions: all dynamically allocated memory in nodeArray and the linked list is deallocated

// ------------------------------------------------------------------------------------------------

GraphL::~GraphL() {
	for (int i = 1; i <= size; ++i) {
		clear(nodeArray[i].edgeHead);
	}

	delete[] nodeArray;
}

// ------------------------------------clear--------------------------------------------------- 

// clear: recursively removes all edgeNode objects from the linked list

// preconditions: takes 'EdgeNode *edge' as a parameter
//				  must be called by parent method or recursively called

// postconditions: if edge is not equal to null, all nodes in the linked list are deleted

// --------------------------------------------------------------------------------------------

void GraphL::clear(EdgeNode *edge) {
	if (edge == nullptr) {
		return; 
	}

	clear(edge->nextEdge);
	delete edge;
}

// ------------------------------------buildGraph----------------------------------------------------- 

// buildGraph: creates a graph by reading a file

// preconditions: a valid graph is intialized
// 				  a valid file is provided and opened
//				  method takes 'ifsteam &infile' as a parameter

// postconditions: graph nodes are created 
//				   weighted edges are added to the adjacency list using file data

// ---------------------------------------------------------------------------------------------------

int GraphL::buildGraph(ifstream &infile) {
	if (infile.eof()) {
		return -1;
	}

	string line; 
	getline(infile, line);
	size = stoi(line);

	for (int i = 1; i <= size; ++i) {
        getline(infile, nodeArray[i].data);
    }

    int from, to;

    while (getline(infile, line)) {
		stringstream ss(line);
		ss >> from >> to;

		if (from == 0 && to == 0) {
			break;
		}

		if (from >= 1 && from <= size && to >= 1 && to <= size) {
		EdgeNode *newEdge = new EdgeNode;
		newEdge->adjGraphNode = to;
		newEdge->nextEdge = nodeArray[from].edgeHead;
        nodeArray[from].edgeHead = newEdge; 
		}
    }

    return 1;
}

// ------------------------------------displayGraph-----------------------------------------------------

// displayGraph: displays the graph

// preconditions: a valid graph is intialized with nodes and edges

// postconditions: outputs the graph nodes and each node's edges

// ---------------------------------------------------------------------------------------------------

void GraphL::displayGraph() {
	cout << "Graph: " << endl;
	
	for (int i = 1; i <= size; i++) {
		cout << "Node " << i << string(15, ' ') << nodeArray[i].data << endl;

		EdgeNode *curr = nodeArray[i].edgeHead; 

		while(curr != nullptr) {
			cout << setw(5) << "edge" << setw(5) << i << setw(5) << curr->adjGraphNode << endl;
			curr = curr->nextEdge;
		}

		cout << endl;
	}
}

// ------------------------------------depthFirstSearch-----------------------------------------------------

// depthFirstSearch: performs DFS on the graph and displays nodes in DFS order

// preconditions: a valid graph is intialized with nodes and edges

// postconditions: outputs the graph nodes in DFS order

// ---------------------------------------------------------------------------------------------------

void GraphL::depthFirstSearch() {
	for (int i = 1; i <= size; ++i) {
		nodeArray[i].visited = false;
	}

	vector<int> dfsOrder;

	for (int i = 1; i < size; ++i) {
		if (!nodeArray[i].visited) {
			dfsHelper(i, dfsOrder);
		}
	}

	cout << "Depth-first Ordering : ";

	for (int i : dfsOrder) {
		cout << i << " ";
	}

	cout << endl;
}

// ------------------------------------dfsHelper-----------------------------------------------------

// dfsHelper: recurisvely performs DFS on the graph and stores vised nodes in DFS order

// preconditions: takes 'int index, vector<int> &dfsOrder) as parameters
//				  must be called by parent method or recursively called 

// postconditions: recursively traverses the graph in DFS order, marks nodes as visited 
//					and stores discovered nodes in a vector

// ---------------------------------------------------------------------------------------------------

void GraphL::dfsHelper(int index, vector<int> &dfsOrder) {
	nodeArray[index].visited = true; 

	dfsOrder.push_back(index);

	EdgeNode *edge = nodeArray[index].edgeHead;
	
	while (edge != nullptr) {
		int dest = edge->adjGraphNode;

		if (!nodeArray[dest].visited) {
			dfsHelper(dest, dfsOrder);
		}

		edge = edge->nextEdge;
	}
}
