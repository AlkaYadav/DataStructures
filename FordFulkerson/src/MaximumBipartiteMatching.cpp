#include"MaximumBipartiteMatching.h"

void MaximumBipartiteMatching::insertAdjacencyMatrix(int applicants,int jobs){
	this->jobs=jobs;
	this->applicants=applicants;
	for(int i=0;i<applicants;i++){
		cout<<endl<<"For applicant"<<i<<endl;
		for(int j=0;j<jobs;j++){
			cin>>adj[i][j];
		}
	}
}

int MaximumBipartiteMatching::maximumBipartiteMatching(){
	int *seen=new int[jobs];
	int *matchR=new int[jobs];
	int count=0;
	for(int i=0;i<jobs;i++){
		matchR[i]=-1;
	}
	for(int i=0;i<applicants;i++){
		for(int i=0;i<jobs;i++){
			seen[i]=0;
		}
		if(bpm(i,seen,matchR)){
			count++;
		}
	}
	return count;
}

bool MaximumBipartiteMatching::bpm(int applicant,int *seen,int *matchR){
	for(int i=0;i<jobs;i++){
		if(adj[applicant][i] && !seen[i]){
			seen[i]=1;
			if(matchR[i]<0 || bpm(matchR[i],seen,matchR)){
				matchR[i]=applicant;
				return true;
			}
		}
	}
   return false;
}
