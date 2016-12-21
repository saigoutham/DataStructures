#include<iostream>
using namespace std;
int q[20],front=-1,rear=-1,visited[15]={0},d[15]={0};
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
	{
		g->arr[i].head=NULL;
	}
	return g;
}
node *getnode(int data)
{
	node *n=new node;
	n->data=data;
	n->next=NULL;
	return n;
}
node *addedge(graph *g,int src ,int des)
{
	node *n=getnode(des);
	node *temp=g->arr[src].head;
	if(g->arr[src].head==NULL)
		g->arr[src].head=n;
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=n;
	}
}
void bfs(graph *g,int start)
{
	front++;int current;
	q[front]=start;d[start]=0;
	cout<<start<<"==>";
	visited[start]=1;
	while(rear<front)
	{	
		rear++;
		current=q[rear];
		node *temp=g->arr[current].head;
		while(temp!=NULL)
		{
			if(visited[temp->data]==0)
			{
				d[temp->data]=d[current]+1;
				//cout<<d[temp->data]<<" ";
				front++;
				q[front]=temp->data;
				cout<<temp->data<<"==>";
				visited[temp->data]=1;

			}
			temp=temp->next;
		}

	}
}

void print(graph *g)
{
	int v=g->v;
	for(int i=0;i<v;i++)
	{
		node *temp=g->arr[i].head;
		cout<<"\nAdjacency list of "<<i<<"is : ";
		while(temp!=NULL)
		{
			cout<<temp->data<<"->";
			temp=temp->next;
		}

	}
	cout<<"\n";
}
int main()
{
	int n,src,des;char c;
	cout<<"Enter the number of vertices in a graph : ";
	cin>>n;
	graph *g=createGraph(n);
	if(n!=0)
	{
		do
		{
				cout<<"Enter source and destination : ";
				cin>>src>>des;
				addedge(g,src,des);
				cout<<"Do you want to add more edges : ";
				cin>>c;
		}while(c=='y'||c=='Y');
	}
	print(g);
	int start;
	cout<<"Enter starting vertex : ";
	cin>>start;
	bfs(g,start);
	cout<<"Distances from starting vertex : ";
	for(int i=0;i<v;i++)
	{
		cout<<d[i]<<" ";
	}

		
	
	return 0;
}