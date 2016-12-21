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
int find_parent(int parent[],int x)
{
    if(parent[x]==-1)
    return x;
    else 
    find_parent(parent, parent[x]);
}
void uni(int parent[],int x,int y)
{
    int xset=find_parent(parent,x);
    int yset=find_parent(parent,y);
    parent[xset]=yset;
}
graph *createGraph(int v,int e)
{
    graph *g=new graph;
    g->v=v;
    g->e=e;
    g->edge=new Edge[g->e];
    return g;
}
int isCycle(graph *g)
{
    int parent[g->v];
    for(int i=0;i<g->v;i++)
    parent[i]=-1;
    for(int i=0;i<g->e;i++)
    {
        int x=find_parent(parent,g->edge[i].src);
        int y=find_parent(parent,g->edge[i].des);
        if(x==y)
        return 1;
        uni(parent,x,y);
    }
    return 0;
}
int main()
{
    int v,e;int src,des;
    cout<<"Enter number of vertices and edges in graph : ";
    cin>>v>>e;
    graph *g=createGraph(v,e);
    for(int i=0;i<g->e;i++)
    {
        cout<<"Enter source and destination for edge :"<<i;
        cin>>src>>des;
        g->edge[i].src=src;
        g->edge[i].des=des;
    }
    int check=isCycle(g);
    if(check==1)
    cout<<"Graph has a cycle : ";
    else 
    cout<<"Graph does not have a cycle :";
    return 0;
}
