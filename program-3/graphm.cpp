// ------------------------------------------------ graphm.cpp ----------------------------------------------------------

// Dylan Nelson CSS 343 A

// Creation Date
// 11/3/24

// Date of Last Modification
// 11/9/24

// ---------------------------------------------------------------------------------------------------------------------

// File implements declared methods in graphm.h 

// --------------------------------------------------------------------------------------------------------------------- 

// File is expected to implement methods and functions from graphm.h to create a weighted directed graph 
//      using an adjacency matrix 
//
// Used special algorithm "Dijkstra's Algorithm" to find the shortest path between nodes 

// ---------------------------------------------------------------------------------------------------------------------

#include "graphm.h"

// ------------------------------------GraphM----------------------------------------------------- 

// GraphM: constructs graphm

// preconditions: assumes constructor will run when object is initialized 

// postconditions: if object is initialized, initializes adjacency matrix C and 
//					TableType T to empty

// -----------------------------------------------------------------------------------------------

GraphM::GraphM() : size(0) {
	for (int i = 0; i < MAXNODES; ++i) {
		for (int j = 0; j < MAXNODES; ++j) {
			C[i][j] = INT_MAX;
			T[i][j]= {false, INT_MAX, 0};
		}
	}	
}

// ------------------------------------buildGraph----------------------------------------------------- 

// buildGraph: creates a graph by reading a file

// preconditions: a valid graph is intialized
// 				  a valid file is provided and opened
//				  method takes 'ifsteam &infile' as a parameter

// postconditions: graph nodes are created 
//				   weighted edges are added to the adjacency matrix using file data

// ---------------------------------------------------------------------------------------------------

int GraphM::buildGraph(ifstream &infile) {
	if (infile.eof()) {
        return -1;
    }
	
	string line; 
	getline(infile, line);
	size = stoi(line);

    for (int i = 1; i <= size; ++i) {
        getline(infile, data[i]);
    }

    int from, to, cost;

    while (getline(infile, line)) {
        stringstream ss(line);
		ss >> from >> to >> cost;

		if (from == 0 && to == 0 && cost ==0) {
			break;
		}

		if (from >= 1 && from <= size && to >= 1 && to <= size) {
			C[from][to] = cost; 		
		}
        
    }

    return 1; 
}

// ------------------------------------insertEdge----------------------------------------------- 

// insertEdge: inserts a directed, non-duplicate, weighted edge between two nodes in the graph

// preconditions: a valid graph is intialized that contains at least two nodes
//				  method takes 'int from, int to, int cost' as parameters   

// postconditions: if two nodes exist in the graph that do not have a weighted edge between 
//					them, inserts directed weighted edge

// ---------------------------------------------------------------------------------------------

int GraphM::insertEdge(int from, int to, int cost) {
	if (hasEdge(from, to)) {
		cout << "Unable to insert duplicate edge" << endl;
		return -1;
	}
	
	if (from == to || cost < 0) {
		return -1;
	}

	C[from][to] = cost;

	return 1; 
}

// ------------------------------------removeEdge--------------------------------------------------- 

// removeEdge: removes directed edge between two graph nodes

// preconditions: a valid graph is intialized that contains at least two nodes
//                method takes 'int from, int to' as parameters 

// postconditions: if edge exists between two nodes, removes edge by updating edge 
// 					weight to infinity

// -------------------------------------------------------------------------------------------------

int GraphM::removeEdge(int from, int to) {
	if (!hasEdge(from, to)) {
		return -1;
	}
	
	C[from][to] = INT_MAX;
	
	return 1;
}

// ------------------------------------hasEdge--------------------------------------------------- 

// hasEdge: checks if a valid edge exists between two nodes

// preconditions: a valid graph is intialized that contains at least two nodes
//                method takes 'int from, int to' as parameters  

// postconditions: returns true if weighted edge exists between two nodes, 
//					otherwise returns false

// ---------------------------------------------------------------------------------------------

bool GraphM::hasEdge(int from, int to) {
	if (from < 1 || from > size || to < 1 || to > size) {
		return false;
	}

	return C[from][to] != INT_MAX;
}

// ------------------------------------findShortestPath-------------------------------------------------

// findShortestPath: calculates the shortest paths from each node to all other nodes in the graph 
// 						using Dijkstra's Algorithm

// preconditions: a valid graph is intialized that contains at least two nodes 

// postconditions: updates TableType T with shortest path distances and paths between each node
//					and every other node

// ------------------------------------------------------------------------------------------------------

void GraphM::findShortestPath() {
	for (int src = 1; src <= size; ++src) {
		for (int i = 1; i <= size; ++i) {
			T[src][i]= {false, INT_MAX, 0};
		}

		T[src][src].dist = 0;

		for (int i = 1; i <= size; ++i) {
			int v = -1;
			int minDist = INT_MAX; 
			
			for (int j = 1; j <= size; ++j) {
				if (!T[src][j].visited && T[src][j].dist <= minDist) {
					v = j;
					minDist = T[src][j].dist;
				}
			}

			if (v == -1) {
				break;
			}

			T[src][v].visited = true;

			for (int w = 1; w <= size; ++w) {
				if (!T[src][w].visited && C[v][w] != INT_MAX) {
					int newDist = T[src][v].dist + C[v][w];
					int originalDist = T[src][w].dist;
					if (newDist < 0) {
						break;
					}

					T[src][w].dist = min(T[src][w].dist, newDist);
					
					if (T[src][w].dist != originalDist) {
						T[src][w].path = v;
                    }
				}
			}
		}
	}
}

// ------------------------------------display--------------------------------------------------------

// display: displays the shortest path and distance between two graph nodes

// preconditions: a valid graph is intialized that contains at least two nodes 
//				  method takes 'int from, int to' as parameters  

// postconditions: shortest path and distance between two graph nodes is displayed

// ---------------------------------------------------------------------------------------------------

void GraphM::display(int from, int to) {
	vector<int> vPath = displayHelper(from, to, 10);

	if (vPath.size() > 0) {
		for (auto it = vPath.rbegin(); it != vPath.rend(); ++it) {
			cout << data[*it] << endl;
		}
		cout << endl;
	}

	cout << endl;
}

// ------------------------------------displayAll-----------------------------------------------------

// displayAll: displays the shortest paths and distances between all nodes

// preconditions: a valid graph is intialized that contains at least two nodes 

// postconditions: all shortest paths and distances between graph nodes are displayed

// ---------------------------------------------------------------------------------------------------

void GraphM::displayAll() {
	cout << "Description" << setw(20) << "From node" << setw(10) << "To node" << setw(15) << "Distance" << setw(10) << "Path" << endl;
		
	for (int from = 1; from <= size; ++from) {
		cout << data[from]<< endl;
		for (int to = 1; to <= size; ++to) {
			if (from == to) {
				continue;
			}
			
			displayHelper(from, to, 30);
		}
	}
	
	cout << endl;
}

// ------------------------------------displayHelper-----------------------------------------------------

// displayHelper:Formats and displays the shortest path and distances between two nodes

// preconditions: a valid graph is intialized that contains at least two nodes 
//				  method takes 'int from, int to, int space' as parameters    

// postconditions: graph is proprely formatted
//				   shortest paths and distances are displayed

// ---------------------------------------------------------------------------------------------------

vector<int> GraphM::displayHelper(int from, int to, int space) {
	cout<< setw(space) << from << setw(10) << to << setw(15);
	
	vector<int> vPath;
	 
	if (T[from][to].dist == INT_MAX) {
		cout <<  "---";
	} else {
		cout<< T[from][to].dist << setw(10);

		int pathNode = to;

		while (pathNode != from) {
			vPath.push_back(pathNode);
			pathNode = T[from][pathNode].path;
		}

		vPath.push_back(from);

		for (auto it = vPath.rbegin(); it != vPath.rend(); ++it) {
			cout << *it << " ";
		}
	}

	cout << endl;
	return vPath;
}
