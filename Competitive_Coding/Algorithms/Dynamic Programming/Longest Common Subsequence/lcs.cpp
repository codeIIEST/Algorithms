
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define infinite 0xffff
#define Min(a,b)  (((a)<(b))?(a):(b))
#define Max(a,b)  (((a)>(b))?(a):(b))
#define fr(i,j,s) for(i = j ; i < s ; i++)
#define ifr(i,j,s) for(i = j ; i >= s , i--)
void lcs(char * a, char *b)
{
    lli lena,lenb,i,j,count;
    lena=strlen(a);
    lenb=strlen(b);
    char record[lena+1][lenb+1];
    //Code to generate the map
    fr(i,0,lena+1)
    {
        fr(j,0,lenb+1)
        {
            if(i==0 || j==0)
            {
                record[i][j]=0;
            }
            else if(a[i-1]==b[j-1])
            {
                record[i][j]=record[i-1][j-1]+1;
            }
            else
            {
                record[i][j] = Max(record[i-1][j],record[i][j-1]);
            }
        }
    }
    //Code to find the subsequence
    i = lena;
    j = lenb;
    char sub[record[lena][lenb]];
    lli index = record[i][j]-1;
    while( i > 0 && j > 0 )
    {
        if(a[i-1]==b[j-1])
        {
            sub[index]=a[i-1];
            i--;
            j--;
            index--;
        }
        else if(Max(record[i-1][j],record[i][j-1]) == record[i-1][j])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    fr(i,0,record[lena][lenb])
    {
        cout<<sub[i]<<" ";
    }
    cout<<endl;
}
int main(void)
{
    lli n,i;
    char str1[1000];
    char str2[1000];
    cin>>str1;
    cin>>str2;
    lcs(str1,str2);
    return 0;
}
