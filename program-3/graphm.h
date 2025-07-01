// ------------------------------------------------ graphm.h -----------------------------------------------------------

// Dylan Nelson CSS 343 A

// Creation Date
// 11/3/24

// Date of Last Modification
// 11/9/24

// ---------------------------------------------------------------------------------------------------------------------

// This file defines methods and variables to be implemented in graphm.cpp

// ---------------------------------------------------------------------------------------------------------------------

// No assumptions or special algorithms implemented in this file, file is included in graphm.cpp

// ---------------------------------------------------------------------------------------------------------------------

#pragma once

#include <iostream>
#include <climits>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

const int MAXNODES = 101;

struct TableType {
	bool visited;          // whether node has been visited
	int dist;              // shortest distance from source known so far
	int path;              // previous node in path of min dist
};

class GraphM {                           
public:
	GraphM();
	int buildGraph(ifstream &infile);
	int insertEdge(int from, int to, int cost);
	int removeEdge(int from, int to);
	void findShortestPath();
	void display(int from, int to);
	void displayAll();

private:
	string data[MAXNODES];              // data for graph nodes
	int C[MAXNODES][MAXNODES];            // Cost array, the adjacency matrix
	int size;                             // number of nodes in the graph
	TableType T[MAXNODES][MAXNODES];      // stores visited, distance, path
	bool hasEdge(int from, int to);
	vector<int> displayHelper(int from, int to, int space);
};
