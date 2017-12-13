#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define md 1000000007
#define ll long long int
#define vi vector<int>
#define vll vector<i64>
#define pb push_back
#define all(c) (c).begin(),(c).end()
template< class T > T max2(const T &a,const T &b) {return (a < b ? b : a);}
template< class T > T min2(const T &a,const T &b) {return (a > b ? b : a);}
template< class T > T max3(const T &a, const T &b, const T &c) { return max2(a, max2(b, c)); }
template< class T > T min3(const T &a, const T &b, const T &c) { return min2(a, min2(b, c)); }
template< class T > T gcd(const T a, const T b) { return (b ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(const T a, const T b) { return (a / gcd<T>(a, b) * b); }
template< class T > T mod(const T &a, const T &b) { return (a < b ? a : a % b); }
typedef pair<ll,ll> pi;
int main()
{
    fastio;
    string txt;
    string pat;
    getline(cin,txt);//getline() reads the complete line in contrary to the traditional cin function which reads just the string before any spaces
    getline(cin,pat);
    int n = txt.length();
    int pat_len = pat.length();
    string str = pat + "$" + txt;//This is the new string that is formed after merging the pattern, '$' and txt string . we can use any other symbol instead of '$'.I have used dollar sign because it occurs rarely in the txt string

    int len = n+pat_len +1;//length of the total output string
    int z_val[len]={0};
    int left =0;//left index of the z box
    int right =0;//right index of the z box
    int count=0;//count of the match
    for(int i=1;i<len;i++)
    {
        int curr = i;
        if(count>1)
        {
            left =i;
            right = i + count-2;
        }


        if(count<=1)
        {
            count=0;
        for(int j=0;j<curr && j<len;j++)
        {
            if(str[j]==str[curr])
            {
                count++;
                curr++;
            }
            else
            {
                z_val[i]=count;
                break;

            }
        }
        }
        else
        {
            for(int j=left;j<=right; j++)
            {
                if(z_val[j-left]+j<right)//looks for the edge cases when the string index + the assigned z value surpasses the right index..this is not possible.So we need to check the match for given letter saperately.
                    z_val[j]=z_val[j-left];
                else
                {
                    count=0;
                    i=j-1;
                    break;
                }
            }
        }
    }
    for(int i=0;i<len;i++)
    {
        if(z_val[i]==pat_len)//This indicates the index where the string occurence takes place
            cout<<i-pat_len<<endl;
    }


}
