"""
The algorithm uses a procedure called Shell Sort
to sort the lists. It breaks the list to smaller sublists
and each sublist is further sorted by insertion sort.
The sublists are made using a gap and elements at gap i
is often selected and forms a sublist.
"""

def shellSort(test):
    sublistcount = len(test)//2 #Finds gap to create sublists
    while(sublistcount > 0):
	for startposition in range(sublistcount):
		gapInsertionSort(test,startposition,sublistcount)
	print("After increments of size",sublistcount,"The list is",test)
	sublistcount = sublistcount // 2

def gapInsertionSort(test,start,gap):
	for i in range(start+gap,len(test),gap):
		currentvalue = test[i]
		position = i
		while(position>=gap and test[position-gap]>currentvalue):
			test[position]=test[position-gap]
			position = position-gap
		test[position]=currentvalue

if __name__=="__main__":
    test = [99,109,29,89,44,98,20,55,31]
    shellSort(test)
    print test
