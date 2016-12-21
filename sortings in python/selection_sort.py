array=list(map(int,input().split()))
for j in range(0,len(array)):
    min=array[j]
    for i in range(j+1,len(array)):
        if array[i]<min :
            min=array[i]
            index=i
    array[index],array[j]=array[j],array[index]

print(array)
