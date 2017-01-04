
#include<iostream>
#include<cstdio>

using namespace std;

int visited[20]={0};
int s[20],top=-1;
struct node
{
    int data;
    node *next;
};

struct adjlist
{
    node *head;
};

struct graph
{
    int v;
    adjlist *arr;
};

graph *createGraph(int v)
{
    graph *g=new graph;
    g->v=v;
    g->arr=new adjlist[v];
    for(int i=0;i<v;i++)
        g->arr[i].head=NULL;
    return g;
}
node *getNode(int data)
{
    node *n = new node;
    n->data = data;
    n->next = NULL;
    return n;

}
void addEdge(graph *g,int src , int des )
{
    node *n=getNode(des);

    if(g->arr[src].head==NULL)
        g->arr[src].head=n;
    else
    {
        node *temp=g->arr[src].head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=n;

    }

}
void print(graph *g)
{
    for(int i=0;i<g->v;i++)
    {
        cout<<"Adjacency list of "<<i<<" is : ";
        node *temp=g->arr[i].head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->next;

        }
        cout<<endl;
    }

}
void dfs(graph *g,int start)
{
    visited[start]=1;
    cout<<start<<" ";
    s[top++]=start;
    node *temp=g->arr[start].head;
    for(;temp!=NULL;temp=temp->next)
    {
        if(visited[temp->data]==0)
            dfs(g,temp->data);
    }
}
int main()
{
    int v,src,des;char c;
    cout<<"Enter the number of vertices in graph : ";
    cin>>v;
    if(v==0)
    {
        cout<<"Graph does not exist with 0 vertices : ";
        return 0;
    }
    graph *g=createGraph(v);
    do
    {
        cout<<"Enter source and destination : ";
        cin>>src>>des;
        addEdge(g,src,des);
        cout<<"Press y to add more edges ";
        cin>>c;

    }while(c=='y');
    print(g);
    cout<<"Enter starting vertex for dfs : ";
    cin>>src;
    dfs(g,src);

    return 0;
}
