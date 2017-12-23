# A dynamic programming based function to find nth
# Catalan number
def catalanDP(n):
    if (n == 0 or n == 1):
        return 1
    # Table to store results of subproblems
    catalan = [0 for i in range(n + 1)]
    # Initialize first two values in table
    catalan[0] = 1
    catalan[1] = 1
    # Fill entries in catalan[] using recursive formula
    for i in range(2, n + 1):
        catalan[i] = 0
        for j in range(i):
            catalan[i] = catalan[i] + catalan[j] * catalan[i-j-1]
    # Return last entry
    return catalan[n]
# Driver code
for i in range (11):
    print (catalanDP(i))
