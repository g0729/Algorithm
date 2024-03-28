#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    ll n;
    cin>>n;

    vector<ll> v(n);

    for (ll i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    
    ll cnt=0;

    ll left=0;
    ll right=0;
    for (ll i = 0; i < n; i++)
    {
        if(v[i]%2==0)
        {
            left+=i;
            left-=cnt;
            cnt++;
        }
    }

    cnt=0;
    for (ll i = 0; i < n; i++)
    {
        if(v[i]%2==1)
        {
            right+=i;
            right-=cnt;
            cnt++;
        }
    }
    
    cout<<min(left,right);
    
    return 0;
}