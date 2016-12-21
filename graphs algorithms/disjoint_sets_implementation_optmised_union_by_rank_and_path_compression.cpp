struct node
{
	int data;
	int rank;
	node *parent;
	
};
//create a node
//insert data into it and make it point to itself
node *make_set(int data)
{
	node *n=new node;
	n->data=data;
	n->root=0;
	n->parent=n;
	return n;
}
//returns parent pointer and it uses path compression
//n->parent=find_set(n->parent);
//	return n->parent;
//The above two steps makes path compression possible
node *find_set(node *n)
{
	if(n->parent==n)
		return n;
	n->parent=find_set(n->parent);
	return n->parent;
}
//It follows union by rank
//The node which has more rank is made parent of that union set
void union_set(node *x,node *y)
{
	node *a=find_set(x);
	node *b=find_set(y);
	if(a==b)//if both are in same set no need to union
		return;
	else
	{
		if(a->rank>b->rank)
		{
			b->parent=a;
			a->rank++;
		}
		else if(a->rank<b->rank)
		{
			a->parent=b;
			b->rank++;
		}
		else
		{
			b->parent=a;
			a->rank++;

		}
	}
}
int main()
{
	int e;
	cout<<"Enter number of elements in set ";
	cin>>n;
	node *n[e];
	for(int i=0;i<e;i++)
		n[i]=make_set(i);
}