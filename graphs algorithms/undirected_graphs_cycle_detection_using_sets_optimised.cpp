#include<iostream>
using namespace std;
struct node 
{
	int data;
	int rank;
	node *parent;
};
node *make_set(int data)
{
	node *n=new node;
	n->data=data;
	n->rank=0;
	n->parent=n;
	return n;
}
node *find_set(node *n)
{
	if(n->parent==n)
		return n;
	n->parent=find_set(n->parent);
	return n->parent;
}
void union_set(node *x,node *y)
{
	node *x_p=find_set(x);
	node *y_p=find_set(y);
	if(x_p==y_p)
		return;
	else
	{
		if(x_p->rank>y_p->rank)
		{
			y_p->parent=x_p;
			x_p->rank++;
		}
		else if(x_p->rank<y_p->rank)
		{
			x_p->parent=y_p;
			y_p->rank++;
		}
		else
		{
			y_p->parent=x_p;
			x_p->rank++;
		}

	}
}
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
int isCyclic(graph *g)
{
	node *n[g->v];
	for(int i=0;i<g->v;i++)
	{
		n[i]=make_set(i);
	}
	for(int j=0;j<g->e;j++)
	{
		node *x=find_set(n[g->edge[i].src]);
		node *y=find_set(n[g->edge[i].des]);
		if(x==y)
			return 1;
		union_set(x,y);
	}
	return 0;
}
int main()
{
	int v,e;int src,des;
	cout<<"Enter number of vertices in a graph : ";
	cin>>v;
	cout<<"Enter number of edges in a graph : ";
	cin>>e;
	graph *g=createGraph(v,e);
	for(int i=0;i<g->e;i++)
	{
		cout<<"Enter source and destination of edge "<<i+1;
		cin>>src>>des;
		g->edge[i].src=src;
		g->edge[i].des=des;
	}
	if(isCyclic(g))
		cout<<"Graph has a cycle ";
	else
		cout<<"Graph does not have a cycle ";
	return 0;
}