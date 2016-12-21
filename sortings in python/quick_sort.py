def partition(arr,s,e):
    pivot=arr[e]
    i=s-1
    for j in range(s,e-1):
        if arr[j]<pivot:
            i+=1
            arr[i],arr[j]=arr[j],arr[i]
    arr[i+1],arr[e]=arr[e],arr[i+1]
    return i+1
def quicksort(arr,s,e):
    if s<e:
        pivot=partition(arr,s,e)
        quicksort(arr,s,pivot-1)
        quicksort(arr,pivot+1,e)
arr=list(map(int,input("Enter array elements : ").split()))
quicksort(arr,0,len(arr)-1)
print(arr)
