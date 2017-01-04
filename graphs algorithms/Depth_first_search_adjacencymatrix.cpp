#include<iostream>
#include<cstdio>

using namespace std;
int visited[20]={0},v;
int s[20],top=-1;
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
void dfs(int g[][10],int start)
{
    visited[start]=1;
    cout<<start<<" ";
    for(int i=0;i<v;i++)
    {
        if(g[start][i]==1 && visited[i]==0)
            dfs(g,i);




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
    dfs(graph,src);
    return 0;

}
