array=list(map(int,input("Enter elements of an array : ").split()))
element=int(input("Enter element to search : "))
f=0
for i in range(0,len(array)):
            if array[i]==element :
                print("Element Found at  ",i)
                f=1
                break
if f==0 :
            print("Element does not exist in array  : ")
