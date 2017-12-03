def bubbleSort(nlist):
    for passnum in range(len(nlist)-1,0,-1):
        for i in range(passnum):
            if nlist[i]>nlist[i+1]:
                temp = nlist[i]
                nlist[i] = nlist[i+1]
                nlist[i+1] = temp
print("Enter the size of the list")
x=int(input())
print("Enter the elements of the list")
list1=list(map(int,input().split()))
print("Array after bubble sort is")
bubbleSort(list1)
print(list1)
