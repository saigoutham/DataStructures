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
	node *a=find_set(x);
	node *b=find_set(y);
	if(a==b)
		return;
	else
	{
		if(a->rank>b->rank)
		{
			b->parent=a;
			a->rank++;
		}
		else if(a->rank<b->rank)
		{
			a->parent=b;
			b->rank++;
		}
		else
		{
			a->parent=b;
			b->rank++;
		}
	}
}
struct Edge
{
	int src;
	int des;
	int weight;
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
	g->edge=new Edge[g->e];
	return g;
}
void kruskal(graph *g)
{
	node *n[g->v];
	for(int i=0;i<g->v;i++)
		n[i]=make_set(i);
	
	for(int j=0;j<g->e;j++)
	{
		
		node *a=find_set(n[g->edge[j].src]);
		node *b=find_set(n[g->edge[j].des]);
		if(a!=b)
		{
			
			union_set(a,b);
			cout<<g->edge[j].src<<" "<<g->edge[j].des;
			cout<<"\n";
		}

	}
}
int main()
{
	int v,e,src,des,weight;
	cout<<"Enter number of vertices : ";
	cin>>v;
	cout<<"Enter number of edges : ";
	cin>>e;
	graph *g=createGraph(v,e);
	for(int i=0;i<g->e;i++)
	{
		cout<<"Enter source and destion :";
		cin>>src>>des;
		cout<<"Enter weight of the edge : ";
		cin>>weight;
		g->edge[i].src=src;
		g->edge[i].des=des;
		g->edge[i].weight=weight;
	}
	for(int i=0;i<g->e-1;i++)
	{
		int wi=g->edge[i].weight;int wj;
		int index=i;
		for(int j=i+1;j<g->e;j++)
		{
			 wj=g->edge[j].weight;
			if(wi>wj)
			{
				index=j;
			}
		}
		if(index!=i)
		{
			int temps;
				temps=g->edge[i].weight;
				g->edge[i].weight=g->edge[index].weight;
				g->edge[index].weight=temps;
				temps=g->edge[i].src;
				g->edge[i].src=g->edge[index].src;
				g->edge[index].src=temps;
				temps=g->edge[i].des;
				g->edge[i].des=g->edge[index].des;
				g->edge[index].des=temps;
		}
	}
	//for(int k=0;k<g->e;k++)
		//cout<<g->edge[k].weight<<endl;
	kruskal(g);
	return 0;

}