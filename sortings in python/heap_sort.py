def heapify(arr,i):
    largest=i
    left=2*i+1
    right=2*i+2
    if(left<len(arr) and arr[left]>arr[largest]):
        largest=left
    if(right<len(arr) and arr[right]>arr[largest]):
        largest=right
    if(largest!=i):
        arr[largest],arr[i]=arr[i],arr[largest]
        heapify(arr,largest)
arr=list(map(int,input("Enter elements of array : ").split()))
heapify(arr,0)

k=len(arr)
l=list()
for i in range(k-1,0,-1):
    l.append(arr[0])
    del arr[0]
    heapify(arr,0)
l.append(arr[0])

print(l)
