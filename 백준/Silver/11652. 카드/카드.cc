#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    map<lint,int> m;
    int n;
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        lint a;
        cin>>a;
        if(m.find(a)==m.end())
        m.insert({a,1});
        else
        m[a]++;
    }
    
    lint res=0;
    int resCnt=0;
    for(auto it:m)
    {
        if(resCnt<it.second)
        {
            resCnt=it.second;
            res=it.first;
        }
    }

    cout<<res;
    return 0;
}