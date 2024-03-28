#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

vector<ll>Sumtree(4*(MAX+1));
vector<ll>Mintree(4*(MAX+1));
vector<ll>v(MAX+1);
int n;

ll init(int start,int end,int node)
{
    if(start==end)
        return Mintree[node]=v[start];
    
    int mid=(start+end)/2;

    return Mintree[node]=min(init(start,mid,node*2),init(mid+1,end,node*2+1));
}
ll update(int start,int end,int node, int idx,int val)
{
    if(idx<start||idx>end)
        return Sumtree[node];
    
    if(start==end)
    {
        return Sumtree[node]=val;
    }
    int mid=(start+end)/2;

    return Sumtree[node]=update(start,mid,node*2,idx,val)+update(mid+1,end,node*2+1,idx,val);
}
ll Sum(int start,int end,int node,int left,int right)
{
    if(right<start||left>end)
        return 0;
    if(left<=start&&end<=right)
        return Sumtree[node];
    
    int mid=(start+end)/2;

    return Sum(start,mid,node*2,left,right)+Sum(mid+1,end,node*2+1,left,right);
}
ll Min(int start,int end,int node,int left,int right)
{
    if(right<start||left>end)
        return 1e9;
    if(left<=start&&end<=right)
        return Mintree[node];

    int mid=(start+end)/2;

    return min(Min(start,mid,node*2,left,right),Min(mid+1,end,node*2+1,left,right));
}

ll solve(int x,int m)
{
    int l,r;
    int left,right;

    left=0;
    right=x;

    while(left+1<right)
    {
        int mid=(left+right)/2;

        if(Sum(1,n,1,mid,x-1)<=m)
            right=mid;
        else
            left=mid;
    }
    l=right;

    left=x-1;
    right=n+1;

    while(left+1<right)
    {
        int mid=(left+right)/2;

        if(Sum(1,n,1,x,mid)<=m)
            left=mid;
        else
            right=mid;
    }

    r=left+1;

    return Min(1,n,1,l,r);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    
    for (int i = 1; i <= n; i++)
        cin>>v[i];

    init(1,n,1);

    for (int i = 1; i <= n-1; i++)
    {
        int a;
        cin>>a;
        update(1,n,1,i,a);
    }
    int m;
    cin>>m;

    for (int i = 0; i < m; i++)
    {
        string op;
        int a,b;
        cin>>op>>a>>b;

        if(op=="UPDATE")
            update(1,n,1,a,b);
        else
            cout<<solve(a,b)<<"\n";
    }
    
    return 0;
}