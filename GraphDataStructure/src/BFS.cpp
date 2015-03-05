#include "BFS.h"

void BFS::BFS_Graph(AdjacencyList al,int sourcenode){
	queue<int> q;
	int *visited = new int[al.node];
	q.push(sourcenode);
	for(int i=0;i<al.node;i++){
		visited[i]=0;
	}
	while(!q.empty()){
		int value=q.front();
		visited[value]=1;
		cout<<value<<"->";
		q.pop();
		if(al.adjList[value]){
			Node *tmp=al.adjList[value];
			while(tmp){
				if(visited[tmp->data]==0){
				visited[tmp->data]=1;
				q.push(tmp->data);
				}
				tmp=tmp->next;
			}
		}
	}
}

void BFS::printQueueContent(queue<int> q2){
	cout<<endl<<"In the print"<<endl;
	while(!q2.empty()){
		cout<<q2.front()<<"->";
		q2.pop();
	}
}
