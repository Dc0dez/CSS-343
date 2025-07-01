// ------------------------------------------------ my_test.cpp --------------------------------------------------------

// Dylan Nelson CSS 343 A

// Creation Date
// 11/9/24

// Date of Last Modification
// 11/9/24

// ---------------------------------------------------------------------------------------------------------------------

// File is used to test the functionality of all the methods in graphm.cpp and graphl.cpp

// --------------------------------------------------------------------------------------------------------------------- 

// Tests will correctly output expected data if the methods in graphm.cpp and graphl.cpp are structured correctly
// Tests check for correct functionality of buildGraph methods using different file inputs for both graphs; 
//		insertion and removal of edges in graphm; findShortestPath in graphm; depthFirstSearch in graphl, and 
//		displayGraph methods for both graphs

// ---------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include "graphl.h"
#include "graphm.h"
using namespace std;

int main() 
{
	cout<<"\n"<<"Part 1"<<endl; // Tests functionality of graphm buildGraph, findShortestPath, display, and displayAll with "dataUWB.txt"

	ifstream infile1("dataUWB.txt");
	if (!infile1) {
		cout << "File could not be opened." << endl;
		return 1;
	}

	for (;;) {
		if (infile1.eof()) {
			cout<<"No more graphs to read"<<endl;
			break;
		}
		
		GraphM G;

		if (G.buildGraph(infile1) > 0) {
			G.findShortestPath();
			
			cout << "Display all shortest paths" << endl;
			G.displayAll();

			cout << "Display a shortest paths from data[3] to data[1]" <<endl;
			G.display(3, 1);        

			cout << "Display a shortest paths from data[1] to data[2]" <<endl;
			G.display(1, 2);

			cout << "Display a shortest paths from data[1] to data[4]" <<endl;
			G.display(1, 4);
		}
	}

	cout<<"\n"<<"Part 2"<<endl; // Tests functionality of graphl buildGraph, depthFirstSearch, and displayAll with "dataUWB.txt"

	ifstream infile2("dataUWB.txt");
	if (!infile2) {
		cout << "File could not be opened." << endl;
		return 1;
	}

	for (;;) {
		GraphL G;
		
		if (infile2.eof()) {
			cout<<"No more graphs to read"<<endl;
			break;
		}

		if (G.buildGraph(infile2) > 0 ) {
			cout << "Display Graph" << endl;
			G.displayGraph();

			cout << "Display DFS" << endl;
			G.depthFirstSearch();
		}
	}
	
	cout<<"\n"<<"Part 3"<<endl; // Tests functionality of graphl buildGraph, depthFirstSearch, and displayAll with my test file "my_test.txt"
	
	ifstream infile3("my_test.txt");
	if (!infile3) {
		cout << "File could not be opened." << endl;
		return 1;
	}

	for (;;) {
		GraphL G;
		
		if (infile3.eof()){
			cout<<"No more graphs to read"<<endl;
			break;
      	}

		if (G.buildGraph(infile3) > 0 ) {
			cout << "Display Graph" << endl;
			G.displayGraph();

			cout << "Display DFS" << endl;
			G.depthFirstSearch();
		}
	}

	cout<<"\n"<<"Part 4"<<endl; // Tests functionality of graphm buildGraph, findShortestPath, removeEdge, insertEdge, and displayAll with 
							 	// my test file "insert_remove_test.txt"

	ifstream infile4("insert_remove_test.txt");
	if (!infile4) {
		cout << "File could not be opened." << endl;
		return 1;
	}

	for (;;) {
		if (infile4.eof()) {
			cout<<"No more graphs to read"<<endl;
			break;
		}
		
		GraphM G;
		if (G.buildGraph(infile4) > 0) {
			G.findShortestPath();
			cout << "Display all shortest paths before remove" << endl;
			G.displayAll();             

			for (int i = 0; i < MAXNODES; i++) {
				for (int j = 0; j < MAXNODES; j++) {
					G.removeEdge(i, j);
				}
			}

			G.removeEdge(1,2);
			
			G.findShortestPath();
			cout << "Display all shortest paths after remove" << endl;
			G.displayAll(); 

			G.insertEdge(1,2,50);
			G.insertEdge(1,3,20);
			G.insertEdge(1,5,30);
			G.insertEdge(2,4,10);
			G.insertEdge(3,2,20);
			G.insertEdge(3,4,40);
			G.insertEdge(5,2,20);
			G.insertEdge(5,4,25);

			G.findShortestPath();
			cout << "Display all shortest paths after insert" << endl;
			G.displayAll(); 

			cout<<endl;
			G.insertEdge(1,2,50);
			cout<<endl;
		}
	}

	cout<<"\n"<<"Part 5"<<endl; // Tests functionality of graphm buildGraph, findShortestPath, insertEdge, and displayAll with 
							 	// blank test file "blank.txt"

	ifstream infile5("blank.txt");
	if (!infile5) {
		cout << "File could not be opened." << endl;
		return 1;
	}

	for (;;) {
		if (infile5.eof()) {
			cout<<"No more graphs to read"<<endl;
			break;
		}
		
		GraphM G;
		if (G.buildGraph(infile5) > 0) {
			G.findShortestPath();
			cout << "Display all shortest paths before insert" << endl;
			G.displayAll();              

			G.insertEdge(1,2,50);
			G.insertEdge(1,3,20);
			G.insertEdge(1,5,30);
			G.insertEdge(2,4,10);
			G.insertEdge(3,2,20);
			G.insertEdge(3,4,40);
			G.insertEdge(5,2,20);
			G.insertEdge(5,4,25);

			G.findShortestPath();
			
			cout << "Display all shortest paths after insert" << endl;
			G.displayAll(); 
		}
	}

	cout << endl;
}
