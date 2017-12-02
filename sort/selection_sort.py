# implementation of selection sort algorithm
# Author: RAHUL THAKUR
# Date: 02 December 2017

def selectionSort(l1):

    size=len(l1)
    i=0
    while i<size:
        smallest=l1[i]
        loc=i
        j=i+1
        while j<size:
            if l1[j]<smallest:
                smallest=l1[j]
                loc=j
            j=j+1
        temp=l1[i]
        l1[i]=smallest
        l1[loc]=temp
        i=i+1
    return l1

print("Enter the elements in the list")

list1=list(map(int,input().split()))

print("After application of Selection Sort Algorithm")

print(selectionSort(list1))
