#Driver function for sorting out the array
def cocktailSort(a):
    #length of the array
	n = len(a)
    #Setting up the flag values
	swap = 1
	start = 0
	end = n-1
	while (swap==1):
        #renewing the swap variable
		swap = 0
		#looping started from right side and headed
        #towards left side
		for i in range (start, end):
			if (a[i] > a[i+1]) :
				a[i], a[i+1]= a[i+1], a[i]
				swap=1

		# if nothing moved, then array is sorted.
		if (swap==0):
			break

		# otherwise, reset the swap flag so that it
		# can be used in the next stage
		swap = 0

		# move the end point back by one, because
		# item at the end is in its rightful spot
		end = end-1

		# from right to left, doing the same
		# comparison as in the previous stage
		for i in range(end-1, start-1,-1):
			if (a[i] > a[i+1]):
				a[i], a[i+1] = a[i+1], a[i]
				swap = 1

		# increase the starting point, because
		# the last stage would have moved the next
		# smallest number to its rightful spot.
		start = start+1
a = []
print("Enter your array")
a = [int(x) for x in input().split()]
cocktailSort(a)
print("Sorted array is:")
for i in range(len(a)):
	print ("%d" %a[i])
