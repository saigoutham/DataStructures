array=list(map(int,input().split()))
for j in range (0,len(array)-1):
    flag=0
    for i in range(0,len(array)-j-1):
        if array[i]>array[i+1]:
            array[i],array[i+1]=array[i+1],array[i]
            flag=1
    if flag==0:
        break
print(array)
