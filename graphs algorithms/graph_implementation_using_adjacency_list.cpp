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
////////////////////////////////////////////////////////////////GLOBAL VARIABLE DECLARATION////////////////////////////////////
int indegree[100]={0},outdegree[100]={0};
node* getnode(int data)
{
	node *n=new node;
	n->data=data;
	n->next=NULL;
	return n;
}
graph*  createGraph(int v)
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
	indegree[des]++;
	outdegree[src]++;
	if(g->arr[src].head==NULL)
	{
		
		g->arr[src].head=n;
		n->next=NULL;
	}
else
{
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=n;
	n->next=NULL;
}
}
void print(graph *g)
{
	int v=g->v;
	for(int i=0;i<v;i++)
	{
		cout<<"Adjacency list of "<<i<<"==>";
	
		node *p=g->arr[i].head;
		while(p!=NULL)
		{
			cout<<p->data<<"-->";
			p=p->next;
		}
		cout<<endl;
	}


}
int main()
{
	int n,src,des;char c;
	cout<<"Enter number of vertices in a graph ";
	cin>>n;
	if(n==0)
	{
		cout<<"Graph does not exist with 0 vertices  : "<<endl;
		return 0;
	}
	graph *g=createGraph(n);
	do
	{
		cout<<"Enter source and destination : ";
		
			cin>>src>>des;
			addedge(g,src,des);
		cout<<"Want to add more edges : ";
		cin>>c;
		
	}while(c=='y'||c=='Y');
	print(g);
	for(int i=0;i<n;i++)
	{
		cout<<"indegree of"<<i<<"is"<<indegree[i]<<endl;
		cout<<"outdegree of"<<i<<"is"<<outdegree[i]<<endl;

	}
	int flag=0;
	for(int i=0;i<n;i++)
	{
		flag=0;
		if(outdegree[i]==n-1)
		{
			continue;
		}
		else
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
		cout<<"Incomplete Graph "<<endl;
	else
		cout<<"complete Graph"<<endl;
	return 0;

}

























