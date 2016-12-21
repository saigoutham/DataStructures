#include<iostream>
using namespace std;
int visited[15]={0},finishing_times[15],stack[10],top=-1;
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
void addedge(graph *g,int src,int des)
{
	node *n=getnode(des);
	node *temp=g->arr[src].head;
	if(g->arr[src].head==NULL)
	{
		g->arr[src].head=n;

	}
	else
	{
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=n;
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

void dfs(graph *g,int start)
{
	//stack[top++]=start;Not need to push into stack coz we are using recursion;

	static int count=0;
	finishing_times[start]=++count;
	cout<<start<<"==>";
	visited[start]=1;
	node *temp=g->arr[start].head;
	while(temp!=NULL)
	{
		if(visited[temp->data]==0)
		{
			dfs(g,temp->data);
			finishing_times[start]=++count;

		}
		else
			temp=temp->next;
		
	
	}


}
void topologicalSort(graph *g,int start)
{
	visited[start]=1;
	node *temp=g->arr[start].head;
	while(temp!=NULL)
	{
		if(visited[temp->data]==0)
			topologicalSort(g,temp->data);
		else
			temp=temp->next;
	}
	stack[++top]=start;
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
	dfs(g,start);
	cout<<"\n";
	cout<<"finishing_times : "<<endl;
	for(int i=0;i<n;i++)
		cout<<finishing_times[i]<<" ";	
	for(int j=0;j<n;j++)
		visited[j]=0;
	cout<<"Enter starting vertex for topologicalSort : ";
	cin>>start;
	topologicalSort(g,start);
	cout<<"\ntopological sort : ";
	
	for(int k=top;k>=0;k--)
		cout<<stack[k]<<"  ";
	return 0;
}





