#ifndef __MaximumBipartiteMatching_H_INCLUDED__   // if x.h hasn't been included yet...
#define __MaximumBipartiteMatching_H_INCLUDED__   //   #define this so the compiler knows it has been included
#include<iostream>
using namespace std;
class MaximumBipartiteMatching{
	int adj[10][10];
	int jobs;
	int applicants;
public:
	void insertAdjacencyMatrix(int applicants,int jobs);
	int maximumBipartiteMatching();
	bool bpm(int applicant,int *seen,int *matchR);
};
#endif
