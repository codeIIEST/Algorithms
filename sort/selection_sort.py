# implementation of selection sort algorithm
# Author: RAHUL THAKUR
# Date: 02 December 2017

def selection_sort(list_param):

    size=len(list_param)
    outer_counter = 0
    while outer_counter < size:

        smallest=list_param[outer_counter]
        loc = outer_counter
        inner_counter = outer_counter + 1

        while inner_counter < size:

            if list_param [ inner_counter] < smallest:
                smallest=list_param[ inner_counter ]
                loc = inner_counter

            inner_counter = inner_counter + 1

        temp=list_param[ outer_counter ]
        list_param[ outer_counter ]=smallest
        list_param[loc]=temp
        outer_counter = outer_counter + 1

    return list_param

print("Enter the elements in the list")

List = list(map(int,input().split()))

print("After application of Selection Sort Algorithm")

print(selection_sort(List))
