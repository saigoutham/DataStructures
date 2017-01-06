#include<iostream>

using namespace std;

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

node *getnode(int data)
{

    node *n=new node;
    n->data=data;
    n->next=NULL;
    return n;
}

graph *createGraph(int v)
{
    graph *g=new graph;
    g->v=v;
    g->arr=new adjlist[v];
    for(int i=0;i<v;i++)
        g->arr[i].head=NULL;
    return g;
}

void addEdge(graph *g,int src,int des)
{
    node *n=getnode(des);

    n->next=g->arr[src].head;
    g->arr[src].head=n;

}
bool dfs(graph *g,int current,bool graySet[],bool blackSet[])
{
    graySet[current]=true;
    node *temp=g->arr[current].head;
    for(;temp!=NULL;temp=temp->next)
    {
        if(blackSet[temp->data]==true)
            continue;
        if(graySet[temp->data]==true)
            return true;
        if(dfs(g,temp->data,graySet,blackSet))
            return true;
    }
    blackSet[current]=true;
    return false;
}
bool hasCycle(graph *g)
{
    bool whiteSet[g->v],graySet[g->v],blackSet[g->v];
    for(int i=0;i<g->v;i++)
    {
        whiteSet[i]=true;
        graySet[i]=false;
        blackSet[i]=false;
    }
    int c=g->v;int i=0;
    while(true)
    {
        if(i==g->v)
            return false;
        if(dfs(g,i,graySet,blackSet))
            return true;
        i++;

    }
    return false;


}
int main()
{
    int v,src,des;char c;
    cout<<"Enter number of vertices in graph : ";
    cin>>v;
    graph *g=createGraph(v);
    if(v==0)
    {
        cout<<"Graph does not exist : ";
        main();
    }

    else
    {
        do
        {
            cout<<"Enter src and des : ";
            cin>>src>>des;
            addEdge(g,src,des);
            cout<<"Press y to add more edges : ";
            cin>>c;
        }while(c=='y');
    }
    if(hasCycle(g))
        cout<<"Graph has a Cycle : ";
    else
        cout<<"Graph does not have a Cycle : ";


    return 0;
}
