#include<iostream>
#include<cstdio>

using namespace std;
int v;
void read(int g[][10])
{
    for(int i=0;i<v;i++)
    {
        char c;int weight;
        for(int j=0;j<v;j++)
        {
            if(i==j)
            {
                g[i][j]=0;
                continue;
            }
            else
            {
                cout<<"Press y to add edge between " <<i<<" and " <<j;
                cin>>c;
                if(c=='y')
                {
                    cout<<"Enter weight of the edge : ";
                    cin>>weight;
                    g[i][j]=weight;

                }
                else
                    g[i][j]=0;

            }
        }
    }
}
int min_key(int key[],bool minspt[])
{
    int m=100,index;
    for(int i=0;i<v;i++)
    {
        if(key[i]<m && minspt[i]==false)
        {
            m=key[i];
            index=i;
        }
    }
    return index;
}
void print_prim(int parent[],int g[][10])
{
    for(int i=1;i<v;i++)
        cout<<i<<" "<<parent[i]<<" "<<g[i][parent[i]]<<endl;

}
void prim(int g[][10])
{
    bool minspt[10];
    int key[10];
    for(int i=0;i<v;i++)
    {
        key[i]=100;
        minspt[i]=false;
    }
    int parent[10];
    key[0]=0;
    parent[0]=-1;
    for(int i=0;i<v-1;i++)
    {
        int u=min_key(key,minspt);

        minspt[u]=true;
        for(int j=0;j<v;j++)
        {
            if(g[u][j]>0&&minspt[j]==false&&g[u][j]<key[j])
            {
                parent[j]=u;
                key[j]=g[u][j];
            }
        }

    }
    print_prim(parent,g);
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
int main()
{
    cout<<"Enter number of vertices in graph : ";
    cin>>v;
    int graph[10][10];
    read(graph);
    prim(graph);
    print(graph);
    return 0;
}
