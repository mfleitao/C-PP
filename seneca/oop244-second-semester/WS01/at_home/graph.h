// Name:			Matheus Leitao	
// Student Number:	148 300 171
// Email:			mfleitao@myseneca.ca	
// Workshop:		Workshop #1: in_home

#ifndef SICT_GRAPH_H 
#define SICT_GRAPH_H

// Maximum number of samples in an graph
#define MAX_NO_OF_SAMPLES 20

namespace sict {

	// Prints a graph comparing the sample values visually 
	void printGraph(int samples[], int);

	// Prints a scaled bar relevant to the maximum value in samples array
	void printBar(int, int);

	// Fills the samples array with the statistic samples
	void getSamples(int samples[], int);

	// Finds the largest sample in the samples array, if it is larger than 70,
	// therwise it will return 70. 
	int findMax(int samples[], int);

}

#endif