#implementation of bubble sort algorithm
# Author: Rahul Thakur
# Date:04 December 2017


#Bubble Sort Function
def bubbleSort(list_param):

    size_list = len(list_param)
    i = 0

    while i<size_list :
        j=0

        while j< size_list-i-1:

            if(list_param[j]>list_param[j+1]):
                temp = list_param[j]
                list_param[j] = list_param[j+1]
                list_param[j+1] = temp

            j = j+1

        i = i+1

    return list_param

print("Enter the size of the list")

x=int(input())

print("Enter the elements of the list")

list1=list(map(int,input().split()))

print("Array after bubble sort is")

print(bubbleSort(list1))
