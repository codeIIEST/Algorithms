#include<bits/stdc++.h>
using namespace std;

void Suff_Arr(string s)
{
    map<string,int> m;
    
    vector<string> v;
    for(int i = 0; i < s.size();i++)
    {
        m[s.substr(i,s.size()-i)] = i;
        v.push_back(s.substr(i,s.size()-i));
    }
    sort(v.begin(),v.end());
    for(int i = 0; i < v.size();i++)
    {
        cout << m[v[i]] <<" ";
    }
  cout<<"\n";
}

int main()
{
    string s;
    cin >> s;
    Suff_Arr(s);
    return 0;
}
