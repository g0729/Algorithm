#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX (ll)600000

vector<ll>tree(4*(MAX+1));
vector<ll>v(MAX+1);
ll update(ll start,ll end,ll node,ll idx,ll val)
{
    if(idx<start||idx>end)
        return tree[node];
    if(start==end)
        return tree[node]=val;

    ll mid=(start+end)/2;

    return tree[node]=max(update(start,mid,node*2,idx,val),update(mid+1,end,node*2+1,idx,val));
}

ll query(ll start,ll end,ll node,ll left,ll right)
{
    if(right<start||left>end)
        return 0;
    if(left<=start&&end<=right)
        return tree[node];

    ll mid=(start+end)/2;

    return max(query(start,mid,node*2,left,right),query(mid+1,end,node*2+1,left,right));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,k,d;

    cin>>n>>k>>d;

    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin>>a;

        ll temp=max(v[a%k],query(1,MAX,1,max((ll)1,a-d),min(MAX,a+d)))+1;

        update(1,MAX,1,a,temp);
        v[a%k]=temp;
    }
    
    cout<<tree[1];
    
    return 0;
}