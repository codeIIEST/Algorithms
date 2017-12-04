#implementation of bubble sort algorithm
# Author: Rahul Thakur
# Date:04 December 2017


#Bubble Sort Function
def bubble_sort(list_param):

    size_list = len(list_param)
    outer_counter = 0                           #variable to be used as iterator

    while outer_counter < size_list :
        inner_counter = 0

        while inner_counter < size_list- outer_counter - 1:

            if( list_param[ inner_counter ] > list_param[ inner_counter+1 ] ):
                temp = list_param[ inner_counter ]
                list_param[ inner_counter ] = list_param[ inner_counter+1 ]
                list_param[ inner_counter+1 ] = temp

            inner_counter = inner_counter + 1

        outer_counter = outer_counter + 1

    return list_param

print( "Enter the size of the list " )

Number_of_elements = int(input())

print( "Enter the elements of the list " )

List=list(map(int,input().split()))

print( "Array after bubble sort is :" )

print(bubble_sort(List))
