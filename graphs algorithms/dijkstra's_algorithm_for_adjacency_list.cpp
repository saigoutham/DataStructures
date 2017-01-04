#include<iostream>
#include<cstdio>

using namespace std;

struct node
{
    int des;
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
graph *createGraph(int v)
{
    graph *g=new graph;
    g->v=v;
    g->arr=new adjlist[v];
    for(int i=0;i<v;i++)
        g->arr[i].head=NULL;
    return g;
}
node *getNode(int des,int weight)
{
    node *n=new node;
    n->des=des;
    n->weight=weight;
    n->next=NULL;
    return n;
}
void addEdge(graph *g,int src,int des,int weight)
{
    node *n=getNode(des,weight);
    n->next=g->arr[src].head;
    g->arr[src].head=n;
    n=getNode(src,weight);
    n->next=g->arr[des].head;
    g->arr[des].head=n;
}
struct heapNode
{
    int v;
    int dis;
};
struct minHeap
{
    int s;
    int capacity;
    int *pos;
    heapNode **a;
};
heapNode *getHeapNode(int v,int dis)
{
    heapNode *n=new heapNode;
    n->v=v;
    n->dis=dis;
    return n;

}
minHeap *createMinHeap(int capacity)
{
    minHeap *heap=new minHeap;
    heap->s=0;
    heap->capacity=capacity;
    heap->pos=new int[capacity];
    heap->a=new heapNode*[capacity];
    return heap;
}
void swap_node(heapNode **a,heapNode **b)
{
    heapNode *t=*a;
    *a=*b;
    *b=t;
}
void heapify(minHeap *heap,int index)
{
    int smallest=index;
    int left=2*index+1;
    int right=2*index+2;
    if(left<heap->s&&heap->a[left]->dis<heap->a[smallest]->dis)
        smallest=left;
    if(right<heap->s&&heap->a[right]->dis<heap->a[smallest]->dis)
        smallest=right;
    if(smallest!=index)
    {
        heapNode *smallestnode=heap->a[smallest];
        heapNode *idxnode=heap->a[index];
        heap->pos[smallestnode->v]=index;
        heap->pos[idxnode->v]=smallest;
        swap_node(&heap->a[smallest],&heap->a[index]);
        heapify(heap,smallest);
    }
}
bool isEmpty(minHeap *heap)
{
    if(heap->s==0)
        return true;
    return false;
}
heapNode *extractMin(minHeap *heap)
{
    if(isEmpty(heap))
        return NULL;
    heapNode *root=heap->a[0];
    heapNode *lastnode=heap->a[heap->s-1];
    heap->pos[root->v]=heap->s-1;
    heap->pos[lastnode->v]=0;
    heap->a[0]=lastnode;
    --heap->s;
    heapify(heap,0);
    return root;
}
void decreaseKey(minHeap *heap,int v,int dis)
{
    int i=heap->pos[v];
    heap->a[i]->dis=dis;
    while(i&&heap->a[i]->dis<heap->a[(i-1)/2]->dis)
    {
        heap->pos[heap->a[i]->v]=(i-1)/2;
        heap->pos[heap->a[(i-1)/2]->v]=i;
        swap_node(&heap->a[i],&heap->a[(i-1)/2]);
        i=(i-1)/2;
    }
}
bool isinHeap(minHeap *heap,int v)
{
    if(heap->pos[v]<heap->s)
        return true;
    return false;
}
void print_dijkstra(int dis[],int v)
{
    for(int i=0;i<v;i++)
        cout<<dis[i]<<endl;
}
void dijkstra(graph *g,int src)
{
    minHeap *heap=createMinHeap(g->v);
    int dis[g->v];
    for(int i=0;i<g->v;i++)
    {
        dis[i]=100;
        heap->a[i]=getHeapNode(i,dis[i]);
        heap->pos[i]=i;
    }
    dis[src]=0;
    heap->a[src]=getHeapNode(src,dis[src]);
    heap->pos[src]=src;
    heap->s=g->v;
    while(!isEmpty(heap))
    {
        heapNode *n=extractMin(heap);
        int u=n->v;
        node *temp=g->arr[u].head;
        for(;temp!=NULL;temp=temp->next)
        {
            int v=temp->des;
            if(isinHeap(heap,v)&&dis[v]>dis[u]+temp->weight)
            {
                dis[v]=dis[u]+temp->weight;
                decreaseKey(heap,v,dis[v]);
            }
        }
    }
    print_dijkstra(dis,g->v);



}
int main()
{
    int V=9;
    graph *g=createGraph(V);
    addEdge(g,0,1,4);
    addEdge(g,0,7,8);
    addEdge(g,1,2,8);
    addEdge(g,1,7,11);
    addEdge(g,2,3,7);
    addEdge(g,2,8,2);
    addEdge(g,2,5,4);
    addEdge(g,3,4,9);
    addEdge(g,3,5,14);
    addEdge(g,4,5,10);
    addEdge(g,5,6,2);
    addEdge(g,6,7,1);
    addEdge(g,6,8,6);
    addEdge(g,7,8,7);
    dijkstra(g,0);
    return 0;

}
