#include<iostream>
#include<cstdio>
#define V 4

using namespace std;

int s[20],top=-1;
void read(int distance[V][V],int path[V][V])
{
    char c;int weight;
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(i==j)
            {
                distance[i][j]=0;
                path[i][j]=8;
            }
            else
            {
                cout<<"Press y to add edge between "<<i<<" and "<<j<<" : ";
                cin>>c;
                if(c=='y')
                {
                    cout<<"Enter weight : ";
                    cin>>weight;
                    distance[i][j]=weight;
                    path[i][j]=i;

                }
                else
                {
                    distance[i][j]=100;
                    path[i][j]=8;
                }
            }
        }
    }
}
void floyd(int distance[V][V],int path[V][V])
{
    for(int k=0;k<V;k++)
    {
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(distance[i][k]==100||distance[k][j]==100)
                    continue;
                else if(distance[i][j]>distance[i][k]+distance[k][j])
                {
                    distance[i][j]=distance[i][k]+distance[k][j];
                    path[i][j]=path[k][j];
                }
            }
        }
    }
}
void print(int matrix[V][V])
{
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;

    }
}
void find_path(int path[V][V],int src,int des)
{

    while(true)
    {
         des=path[src][des];
        s[++top]=des;
        if(des==8)
            return;
        if(des==src)
            break;
    }



}
 int main()
 {
     int distance[V][V],path[V][V];
     read(distance,path);
     print(distance);
     cout<<"\n";
     print(path);
     cout<<"\n";
     floyd(distance,path);
     cout<<"\n";
     print(distance);
     cout<<"\n";
     print(path);
     cout<<"\n";
     int src,des;
     cout<<"Enter src and des for path finding : ";
     cin>>src>>des;
     find_path(path,src,des);
      for(int i=top;i>=0;i--)
        cout<<s[top]<<" ->";
        top=-1;

     return 0;


 }

