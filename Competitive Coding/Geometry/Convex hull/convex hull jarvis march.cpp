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
typedef struct
{
    int x;
    int y;
}point;
int crossprod(point points[],int a,int b,int c)//This function calculates the crossproduct  of the given two vectors . one vector is ab and other is ac.
{
    point current = points[a];
    point target = points[b];
    point temp  = points[c];
    int y1 = target.y-current.y;
    int x1 = target.x-current.x;
    int x2 = temp.x-current.x;
    int y2 = temp.y-current.y;
    return y2*x1-x2*y1;
}
int closer(point points[],int a,int b,int c)//This function calculates the closer of the given two points from a and returns the index of the closer one.
{
    point current = points[a];
    point target = points[b];
    point temp  = points[c];
    double dist1 = sqrt((current.x-target.x)*(current.x-target.x)-(current.y-target.y)*(current.y-target.y));
    double dist2 = sqrt((current.x-temp.x)*(current.x-temp.x)-(current.y-temp.y)*(current.y-temp.y));
    if(dist1<dist2)
        return b;
    else
        return c;
}
int main()
{
    int n;//no of points
    cin>>n;
    point points[n];
    for(int i=0;i<n;i++)
    {
        cin>>points[i].x>>points[i].y;
    }
    //now we look for the leftmost point
    int index=0,mini=100000;
    for(int i=0;i<n;i++)
    {
        if(points[i].x<mini)
        {
            mini=points[i].x;
            index=i;
        }
    }
    set<int> result;

    result.insert(index);//we add the left most point in the result array
    int current = index;//now our index becomes the index to the current point
    vi colinear;
    while(true)
    {
        int target = 0 ;//consider the starting target to be point with index zero
    for(int i=1;i<n;i++)
    {

        if(current==i)//if the current point and the point we are going to compare are the same then nothing below should be executed
        {
            continue;
        }
        else
        {
            int val = crossprod(points,current,target,i);
            if(val > 0)//If the cross prod value is greater than zero than this means that we the point i is in the left side of the line segement that passes through the target and current so now the target needs to be changed.
            {

                target = i;
                colinear.clear();//we also need to clear the colinear array as the target itself is changed.
            }
            if(val  == 0)
            {
                int close = closer(points,current,target,i);//This gives the index of the closer point.
                if(close == target)
                    target = i;
                colinear.pb(close);
            }
        }
    }
    int len =  colinear.size();
    for(int k = 0;k<len;k++)

    colinear.clear();
    if(target == index)//we should end our search if our target becomes equal to the first index we added in the result
    {
        break;
    }
    else
    {

        result.insert(target);
        current = target;
    }
    }
int len = result.size();
 set<int> :: iterator i= result.begin();
for(;i!=result.end();++i)
{
    cout<<points[(*i)].x<<" "<<points[(*i)].y<<endl;
}


}
