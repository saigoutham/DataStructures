#include<iostream>
#include<cstdio>
#define V 4
using namespace std;

void read(int g[V][V])
{
    char c;int weight;
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(i==j)
            {
                g[i][j]=0;
                continue;
            }
            else
            {

                cout<<"press y to add edge from "<<i<<" to "<<j<<" : ";
                cin>>c;
                if(c=='y')
                {
                    cout<<"Weight of the edge : ";
                    cin>>weight;
                    g[i][j]=weight;
                }
                else
                    g[i][j]=0;
            }
        }
    }
}
void print(int g[V][V])
{
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
            cout<<g[i][j]<<" " ;
        cout<<endl;
    }
}
int min_dis(int dis[],bool minspt[])
{
    int m=110,index;
    for(int i=0;i<V;i++)
    {
        if(dis[i]<=m&&minspt[i]==false)
        {
             m=dis[i];
             index=i;
        }

    }
    return index;
}
void print_dijkstra(int parent[],int dis[])
{
    for(int i=0;i<V;i++)
        cout<<dis[i]<<endl;
}
void dijkstra(int g[V][V])
{
    bool minspt[V];
    int dis[V];
    int parent[V];
    for(int i=0;i<V;i++)
    {
        minspt[i]=false;
        dis[i]=100;
    }
    parent[0]=-1;
    dis[0]=0;
    for(int i=0;i<V-1;i++)
    {
        int u=min_dis(dis,minspt);
        minspt[u]=true;
        for(int v=0;v<V;v++)
        {
            if(g[u][v]!=0&&minspt[v]==false&&dis[u]+g[u][v]<dis[v])
            {
                parent[v]=u;
                dis[v]=dis[u]+g[u][v];
            }
        }
    }
    print_dijkstra(parent,dis);
}
int main()
{
    int g[V][V];
    read(g);
    print(g);
    dijkstra(g);
}
