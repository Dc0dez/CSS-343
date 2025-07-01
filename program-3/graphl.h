// ------------------------------------------------ graphl.h ------------------------------------------------------------

// Dylan Nelson CSS 343 A

// Creation Date
// 11/3/24

// Date of Last Modification
// 11/9/24

// ---------------------------------------------------------------------------------------------------------------------

// This file defines methods and variables to be implemented in graphl.cpp

// ---------------------------------------------------------------------------------------------------------------------

// No assumptions or special algorithms implemented in this file, file is included in graphl.cpp

// ---------------------------------------------------------------------------------------------------------------------

#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct EdgeNode;      // forward reference for the compiler

struct GraphNode {    // structs used for simplicity, use classes if desired
	EdgeNode* edgeHead; // head of the list of edges
	string data;     // data information about each node
	bool visited;               
};

struct EdgeNode {
	int adjGraphNode;  // subscript of the adjacent graph node
	EdgeNode* nextEdge;
};

class GraphL {                           
public:
	GraphL();
	virtual ~GraphL();
	int buildGraph(ifstream &infile);
	void displayGraph();
	void depthFirstSearch();

private:
	GraphNode *nodeArray; // array of GraphNodes
	int size;
	void clear(EdgeNode *edge);
	void dfsHelper(int index, vector<int> &dfsOrder);
};
