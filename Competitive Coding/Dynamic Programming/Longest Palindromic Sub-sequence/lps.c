#include<stdio.h>
#include<string.h>
#define MAXLEN 100
// A utility function to get max of two integers
int max (int x, int y) { return (x > y)? x : y; }
 
// Returns the length of the longest palindromic subsequence in seq
int lps(char *str)
{
   int n = strlen(str);
   int i, j, len;
   int mat[n][n];  // Create a table to store results of subproblems
 
 
   // Strings of length 1 are palindrome of lentgh 1
   for (i = 0; i < n; i++)
      mat[i][i] = 1;
 
    /* Build the table. Note that the lower diagonal values of table are
    useless and not filled in the process.  len is length of
    substring*/
    for (len=2; len<=n; len++)
    {
        for (i=0; i<n-len+1; i++)
        {
            j = i+len-1;
            if (str[i] == str[j] && len == 2)
               mat[i][j] = 2;
            else if (str[i] == str[j])
               mat[i][j] = mat[i+1][j-1] + 2;
            else
               mat[i][j] = max(mat[i][j-1], mat[i+1][j]);
        }
    }
 
    return mat[0][n-1];
}
 
/* main */
int main()
{
	printf("Enter your string\n");
	char str[MAXLEN];
	scanf("%99s",str);
    printf ("The lnegth of the Longest Palindromic Sub-sequence is %d", lps(str));
    getchar();
    return 0;
}
