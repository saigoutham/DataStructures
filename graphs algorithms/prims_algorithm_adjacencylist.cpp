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
node *getNode(int des,int weight)
{
    node *n=new node;
    n->des=des;
    n->weight=weight;
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
    int key;
};
struct minHeap
{
    int s;
    int capacity;
    int *pos;
    heapNode **a;
};
minHeap *createHeap(int capacity)
{
    minHeap *heap=new minHeap;
    heap->capacity=capacity;
    heap->s=0;
    heap->pos=new int[capacity];
    heap->a=new heapNode*[capacity];
    return heap;
}
bool isEmpty(minHeap *heap)
{
    if(heap->s==0)
        return true;
    else
        return false;
}
void swap_node(heapNode **a,heapNode **b)
{
    heapNode *t=*a;
    *a=*b;
    *b=t;
}
heapNode *getHeapNode(int v,int key)
{

    heapNode *n=new heapNode;
    n->v=v;
    n->key=key;
    return n;
}
void heapify(minHeap *heap,int index)
{
    int smallest=index;
    int left=2*index+1;
    int right=2*index+2;
    if(left<heap->s&&heap->a[smallest]->key>heap->a[left]->key)
        smallest=left;
    if(right<heap->s&&heap->a[smallest]->key>heap->a[right]->key)
        smallest=right;
    if(smallest!=index)
    {
        heapNode *smallestNode=heap->a[smallest];
        heapNode *idxNode=heap->a[index];
        heap->pos[smallestNode->v]=index;
        heap->pos[idxNode->v]=smallest;
        swap_node(&heap->a[smallest],&heap->a[index]);
        heapify(heap,smallest);
    }
}
heapNode *extractMin(minHeap *heap)
{

    heapNode *root=heap->a[0];
    heapNode *lastNode=heap->a[heap->s-1];
    heap->pos[root->v]=heap->s-1;
    heap->pos[lastNode->v]=0;
    //swap(&heap->a[0],&heap->a[heap->s-1])
    heap->a[0]=lastNode;
    heap->a[heap->s-1]=root;
    --heap->s;
    heapify(heap,0);
    return root;
}
void decreaseKey(minHeap *heap,int v,int key)
{
    int i=heap->pos[v];
    heap->a[i]->key=key;

    while(i&&heap->a[i]->key<heap->a[(i-1)/2]->key)
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
void print_prim(int parent[],int v)
{
    for(int i=1;i<v;i++)
        cout<<i<<" " <<parent[i]<<endl;
}
void prim(graph *g)
{

    minHeap *heap=createHeap(g->v);
    int parent[g->v];
    int key[g->v];
    for(int i=1;i<g->v;i++)
    {

        parent[i]=-1;
        key[i]=100;
        heap->a[i]=getHeapNode(i,key[i]);
        heap->pos[i]=i;
    }
    key[0]=0;
    heap->a[0]=getHeapNode(0,key[0]);
    heap->s=g->v;
    heap->pos[0]=0;
    while(!isEmpty(heap))
    {

        heapNode *minHeapNode=extractMin(heap);
        int u=minHeapNode->v;
        node *temp=g->arr[u].head;
        while(temp!=NULL)
        {

            int v=temp->des;
            if(isinHeap(heap,v)&&key[v]>temp->weight)
            {
                key[v]=temp->weight;
                parent[v]=u;
                decreaseKey(heap,v,key[v]);
            }
            temp=temp->next;
        }
    }

    print_prim(parent,g->v);
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
    prim(g);
    return 0;

}
