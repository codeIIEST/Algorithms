def isSubsetSum(st, n, sm) :
    subset=[[True] * (sm+1)] * (n+1)

    for i in range(0, n+1) :
        subset[i][0] = True
   
    for i in range(1, sm + 1) :
        subset[0][i] = False
   
    for i in range(1, n+1) :
        for j in range(1, sm+1) :
            if(j < st[i-1]) :
                subset[i][j] = subset[i-1][j]
            if (j >= st[i-1]) :
                subset[i][j] = subset[i-1][j] or subset[i - 1][j-st[i-1]]
    return subset[n][sm];

st = [1, 2, 3]
sm = 7
n = len(st)
if (isSubsetSum(st, n, sm) == True) :
    print("Found a subset with given sum")
else :
    print("No subset with given sum")
