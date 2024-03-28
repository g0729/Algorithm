#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,k;

    cin>>n>>m>>k;
    
    int res=0;

    res+=min(m,k);
    
    if(k>m)
    {
        res+=n-k;
    }
    else
    {
        res+=n-m;
    }

    cout<<res;
    return 0;
}