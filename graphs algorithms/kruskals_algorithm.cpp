#include<iostream>
#include<cstdio>

using namespace std;

struct node
{
    int data;
    int r;
    node *parent;
};
node *makeSet(int data)
{
    node *n=new node;
    n->data=data;
    n->r=0;
    n->parent=n;

    return n;
}
node *findSet(node *n)
{
    if(n->parent==n)
        return n;
    n->parent=findSet(n->parent);
    return n->parent;
}
bool union_set(node *x,node *y)
{
    node *a=findSet(x);
    node *b=findSet(y);
    if(a==b)
        return false;
    else
    {
        if(a->r>=b->r)
        {
            b->parent=a;
            a->r++;
            return true;
        }
        else
        {
            a->parent=b;
            b->r++;
            return true;
        }
    }

}
struct Edge
{
    int src,des;
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
        n[i]=makeSet(i);
    for(int i=0;i<g->e-1;i++)
    {
        int min=g->edge[i].weight,index=i;
        for(int j=i+1;j<g->e;j++)
        {
            if(g->edge[j].weight<min)
            {
                min=g->edge[j].weight;
                index=j;
            }
        }
        if(index!=i)
        {
            int temp;
            temp=g->edge[i].weight;
            g->edge[i].weight=g->edge[index].weight;
            g->edge[index].weight=temp;

            temp=g->edge[i].src;
            g->edge[i].src=g->edge[index].src;
            g->edge[index].src=temp;

            temp=g->edge[i].des;
            g->edge[i].des=g->edge[index].des;
            g->edge[index].des=temp;

        }
    }


    for(int i=0;i<g->e;i++)
    {
        if(union_set(n[g->edge[i].src],n[g->edge[i].des]))
            cout<<g->edge[i].src<<" "<<g->edge[i].des<<" "<<g->edge[i].weight<<endl;
    }

}
int main()
{
    int v,e,weight,src,des;
    cout<<"Enter number of vertices in graph : ";
    cin>>v;
    cout<<"Enter number of edges in graph : ";
    cin>>e;
    graph *g=createGraph(v,e);
    for(int i=0;i<g->e;i++)
    {

        cout<<"Enter src and des for edge "<<i+1<<" : ";
        cin>>src>>des;
        cout<<"Enter weight : ";
        cin>>weight;
        g->edge[i].src=src;
        g->edge[i].des=des;
        g->edge[i].weight=weight;

    }

   kruskal(g);
    return 0;
}

