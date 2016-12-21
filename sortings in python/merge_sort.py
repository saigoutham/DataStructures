def merge(arr,s,m,e):
    n1=m-s+1
    n2=e-m
    l1=list()
    l2=list()
    for i in range (0,n1):
        l1.append(arr[s+i])
    for i in range(0,n2):
        l2.append(arr[m+i+1])
    i=0
    j=0
    k=s
    while i<n1 and j<n2 :
        if l1[i]<l2[j]:
            arr[k]=l1[i]
            i+=1
            k+=1
        else :
            arr[k]=l2[j]
            j+=1
            k+=1
    while i<n1:
        arr[k]=l1[i]
        i+=1
        k+=1
    while j<n2:
        arr[k]=l2[j]
        k+=1
        j+=1

def mergesort(arr,s,e):
    if s <e:
        m=(s+e)//2
        mergesort(arr,s,m)
        mergesort(arr,m+1,e)
        merge(arr,s,m,e)
arr=list(map(int,input("Enter elements to sort  : ").split()))
mergesort(arr,0,len(arr)-1)
print(arr)
