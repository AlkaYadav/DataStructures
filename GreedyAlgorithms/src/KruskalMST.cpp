#include "KruskalMST.h"
int KruskalMST::myComp(const void *a,const void *b){
	cout<<"In comparing "<<(((Edge *)a)->weight);
	cout<<"In comparing "<<(((Edge *)b)->weight);
	return (((Edge *)a)->weight) > (((Edge *)b)->weight);
}
void KruskalMST::printKruskalMST(Graph_EdgeList ge){
	//TODO:Sort edges according to edge weights
	qsort(ge.edges,ge.edgeCount,sizeof(ge.edges[0]),myComp);
	cout<<"After sorting"<<endl;
	ge.printGraph();
	int count_vertex=0;
	int edge_index=0;
	UnionFind uf;
	int *parent,*rank;
		parent=new int[ge.vertices];
		rank=new int[ge.vertices];
		for(int i=0;i<ge.vertices;i++){
			parent[i]=-1;
			rank[i]=0;
		}
	while(count_vertex!=ge.vertices-1){
		int source=ge.edges[edge_index].source;
		int destination=ge.edges[edge_index].destination;
		int xfind=uf.find_pathcompression(parent,source);
		int yfind=uf.find_pathcompression(parent,destination);
		if(xfind!=yfind){
			count_vertex++;
			uf.unionVertices_rank(parent,rank,source,destination);
			cout<<"Adding "<<source<<"and "<<destination<<endl;
		}
		edge_index++;
	}
}
