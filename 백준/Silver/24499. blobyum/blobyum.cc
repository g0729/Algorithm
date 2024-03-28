#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int sum=0;

    for (int i = 0; i < k; i++)
    {
        sum+=v[i];
    }
    
    int ans=sum;
    for (int i = k; i < n; i++)
    {
        sum+=v[i];
        sum-=v[i-k];
        ans=max(ans,sum);
    }
    
    for (int i =0; i < k-1; i++)
    {
        sum+=v[i];
        sum-=v[i+n-k];
        ans=max(ans,sum);
    }
    
    cout<<ans;
    return 0;
}