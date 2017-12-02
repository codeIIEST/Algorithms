#implementation of bubble sort algorithm

def bubbleSort(l1):
    size=len(l1)
    i=0
    while i<size :
        j=0
        while j< size-i-1:
            if(l1[j]>l1[j+1]):
                temp=l1[j]
                l1[j]=l1[j+1]
                l1[j+1]=temp
            j=j+1
        #    print(l1)
        i=i+1
    #print(l1)
    return l1
print("Enter the size of the list")
x=int(input())
print("Enter the elements of the list")

list1=list(map(int,input().split()))

print("Array after bubble sort is")
print(bubbleSort(list1))
