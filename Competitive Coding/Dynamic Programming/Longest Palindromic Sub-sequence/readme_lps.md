## Longest Common Subsequence
  In order to solve this problem using Dynamic Programming, we create a 2-D matrix called mat[n][n], where 'n' is the length of the given string.
Any entry [i][j] in the matrix represents the length of the longest palindromic sub-sequence from 'i'th charecter of the string to the 'j'th. 
As the string is always considereed from left to right i<=j always. Hence the lower triangle of the matrix is of no use.

### Filling of the matrix
  Every single charecter contributes to a palindromic string of length 1 starting and ending at itself, therefore we fill the diagonal of the 
matrix with 1 for every [i][i] entry. <br/><br/>
Let str[0..n-1] be the input sequence of length n, then mat[0][n-1] will be the length of the longest palindromic subsequence.<br/>
For every other entry:<br/>
If last and first characters of str are same, then mat[i][j] = mat[i+1][j-1] + 2, as it considers [2(for the first and the last chaar)] + 
[longest palindromic subsequence between these 2 chars].<br/>
Else mat[i][j] = max(mat[i][j-1], mat[i+1][j]).
