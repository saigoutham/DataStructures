#include<iostream>

using namespace std;
struct Edge
{
int src,des;
};
struct graph
{
	int v;
	int e;
	Edge *edge;
};
graph *createGraph(int v,int e)
{
	graph *g=new graph;
	g->v=v;
	g->e=e;
	g->edge=new Edge[g->v];
	return g;
}
int find_parent(int parent[],int x)
{
	if(parent[x]==-1)
		return x;
	else find_parent(parent,parent[x]);
}
void make_set(int parent[],int x,int y)
{
	int xset=find_parent(parent,x);
	int yset=find_parent(parent,y);
	parent[xset]=y;
}
int isCyclic(graph *g)
{
	int parent[g->v];
	for(int i=0;i<g->v;i++)
		parent[i]=-1;
	for(int j=0;j<g->e;j++)
	{
		int x=find_parent(parent,g->edge[j].src);
		int y=find_parent(parent,g->edge[j].des);
		if(x==y)
			return 1;
		make_set(parent,x,y);
	}
	return 0;

}
int main()
{
	int v,e;int src,des;
	cout<<"Enter vertices in a graph : ";
	cin>>v;
	cout<<"Enter edges in a graph : ";
	cin>>e;
	graph *g=createGraph(v,e);
	for(int i=0;i<g->e;i++)
	{
		cout<<"Enter source and destination for edge "<<i+1<<" : ";
		cin>>src>>des;
		g->edge[i].src=src;
		g->edge[i].des=des;

	}
	if(isCyclic(g))
		cout<<"Graph has  a cycle : ";
	else
		cout<<"Graph does not have a cycle : ";
	return 0;

}