#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(),v.end(),greater<int>());

    int res=v[0]+1;

    for (int i = 1; i < v.size(); i++)
    {
        res=max(v[i]+i+1,res);
    }
    
    cout<<res+1;
    return 0;
}