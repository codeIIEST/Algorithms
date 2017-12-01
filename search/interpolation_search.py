# Python program to implement interpolation search
 
# If x is present in arr[0..n-1], then returns
# index of it, else returns -1
def interpolationSearch():
    arr=[]
    n=input("enter array size:")
    for i in range(n):
        put=input("enter element")
        arr.append(put)
    arr.sort()
    x=input("enter element to be searched")

    # Find indexs of two corners
    lo = 0
    hi = (n - 1)
  
    # Since array is sorted, an element present
    # in array must be in range defined by corner
    while lo <= hi and x >= arr[lo] and x <= arr[hi]:
        # Probing the position with keeping
        # uniform distribution in mind.
        pos  = lo + int(((float(hi - lo) /
            ( arr[hi] - arr[lo])) * ( x - arr[lo])))
 
        # Condition of target found
        if arr[pos] == x:
            return pos
  
        # If x is larger, x is in upper part
        if arr[pos] < x:
            lo = pos + 1;
  
        # If x is smaller, x is in lower part
        else:
            hi = pos - 1;
     
    return -1
 
index = interpolationSearch()
 
if index != -1:
    print "Element found"
else:
    print "Element not found"
 
