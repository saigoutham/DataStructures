#include<iostream>
using namespace std;
struct node
{
	int data;
	int weight;
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
node *getnode(int data,int weight)
{
	node *n=new node;
	n->data=data;
	n->weight=weight;
	n->next=NULL;
	return n;
}
graph *creategraph(int v)
{
	graph *g=new graph;
	g->v=v;
	g->arr=new adjlist[g->v];
	for(int i=0;i<g->v;i++)
		g->arr[i].head=NULL;
	return graph;
}
void addedje(graph *g,int src,int des)
{
	node *temp=getnode(src);
	node *temp1=getnode(des);
	if(g->arr[src].head==NULL)
		g->arr[src].head=temp;
	else
	{
		node *check=g->arr[src].head;
		while(check->next!=NULL)
			check=check->next;
		check->next=temp;
	}
	if(g->arr[des].head==NULL)
		g->arr[des].head=temp1;
	else
	{
		node *check=g->arr[des].head;
		while(check->next!=NULL)
			check=check->next;
		check->next=temp1;
	}
}
struct heapnode
{
	int key;
	int v;
	
};
struct minheap
{
	int size;
	int capacity;
	int *pos;
	heapnode **a;
	
};
minheap *createheap(int capacity)
{
	minheap *heap=new minheap;
	heap->size=0;
	heap->capacity=capacity;
	heap->pos=new int[capacity];
	heap->a=new *heapnode[capacity];
	return heap;
}
heapnode *getheapnode(int key,int v)
{
	heapnode *h=new heapnode;
	h->key=key;
	h->v=v;
	return h;
}
void swap(heapnode **a,heapnode **b)
{
	heapnode *t;
	*t=*a;
	*a=*b;
	*b=*t;
}
void heapify(minheap *heap,int idx)
{
	int smallest=idx;
	int left=2*smallest+1;
	int right=2*smallest+2;
	if(left<heap->size&&heap->a[smallest]->key>heap->a[left]->key)
		smallest=left;
	if(right<=heap->size&&heap->a[smallest]->key>heap->a[right]->key)
		smallest=right;
	if(smallest!=index)
	{
		heapnode *smallestnode=heap->arr[smallest];
		heapnode *idxnode=heap->arr[idx];
		heap->pos[smallestnode->v]=idx;
		heap->pos[idxnode->v]=smallest;
		swap(&heap->arr[smallest],heap->arr[smallest]);
		heapify(heap,smallest);
	}
}
int isempty(minheap *heap)
{
	return heap->size==0 ;
}
heapnode *extractmin(minheap *heap)
{
	if(isempty(heap))
		return NULL;
	heapnode *min=heap->a[0];
	heapnode *last=heap->a[heap->size-1];
	heap->a[0]=last;
	
	heap->pos[min->v]=heap->size-1;
	heap->pos[last->v]=0;
	heap->size--;
	heapify(heap,0);
	return min;
}
void decrease(minheap *heap,int key,int v)
{
	int i=heap->pos[v];
	heap->a[i]->key=key;
	while(i&&heap->a[i]->key<heap->a[(i-1)/2]->key)
	{
		heap->pos[heap->a[i]->v]=(i-1)/2;
		heap->pos[heap->a[(i-1)/2]->v]=i;
		swap(&heap->a[i],&key<heap->a[(i-1)/2]);
		i=(i-1)/2;
	}

}
bool isinheap(minheap *heap,int v)
{
	if(heap->pos[v]<heap->size)
		return true;
	return false;
}
void print(int arr[],int n)
{
	for(int i=1;i<n;i++)
		cout<<arr[i]<<"\t"<<i<<endl;
}
void prim(graph *g)
{
	int key[g->v];
	int v=g->v;
	int parent[g->v];
	minheap *heap=creategraph(v);
	for(int i=1;i<v;i++)
	{
		key[i]=100;
		parent[i]=-1;
		heap->a[i]=getheapnode(i,key[i]);
		heap->pos[i]=i;
	}
	key[0]=0;
	heap->a[0]=getheapnode(0,key[0]);
	heapnode *min=extractmin(heap);
}