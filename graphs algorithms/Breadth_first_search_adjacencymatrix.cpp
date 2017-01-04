#include<iostream>
#include<cstdio>

using namespace std;
int v;int q[20],f=-1,r=-1,visited[20]={0};
void read(int g[][10])
{
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            char c;
            if(i==j)
            {
                g[i][j]=0;
                continue;
            }
            else
            {
                cout<<"Edge from "<<i<<" to "<<j<<" : ";
                cin>>c;
                if(c=='y')
                    g[i][j]=1;
                else
                    g[i][j]=0;

            }
        }

    }
}
void print(int g[][10])
{
    for(int i=0;i<v;i++)
    {

        for(int j=0;j<v;j++)
            cout<<g[i][j]<<" ";
        cout<<endl;
    }


}
void bfs(int g[][10],int start)
{
    visited[start]=1;
    cout<<start<<" ";
    q[f++]=start;
    while(r<f)
    {
        start=q[r++];

        for(int i=0;i<v;i++)
        {
            if(g[start][i]==1)
            {
                if(visited[i]==0)
                {
                    visited[i]=1;
                    cout<<i<<" ";
                    q[f++]=i;
                }
            }
        }
    }


}
int main()
{

    cout<<"Enter number of vertices : ";
    cin>>v;
    int graph[10][10];
    read(graph);
    print(graph);
    cout<<"Enter starting vertex for bfs : ";
    int src;
    cin>>src;
    bfs(graph,src);
    return 0;

}
