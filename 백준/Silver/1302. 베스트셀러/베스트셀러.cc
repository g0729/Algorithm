#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    map<string, int> ma;

    int n;
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin>>s;
        if(ma.find(s)==ma.end())
        {
            ma.insert({s,1});
        }
        else
        ma[s]++;
    }
    int MAX=0;
    string res;
    for(auto it:ma)
    {
        if(it.second>MAX)
        {
            MAX=it.second;
            res=it.first;
        }
    }

    cout<<res;
    
    return 0;

}