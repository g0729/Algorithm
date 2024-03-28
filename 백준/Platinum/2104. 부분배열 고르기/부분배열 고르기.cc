#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
#define MOD 1000000007
lint n;
vector<lint> Sumtree;
vector<lint> Mlintree;
vector<lint> v;
lint res;

lint Suminit(lint start, lint end, lint node)
{
    if (start == end)
        return Sumtree[node] = v[start];

    lint mid = (start + end) / 2;

    return Sumtree[node] = Suminit(start, mid, node * 2) + Suminit(mid + 1, end, node * 2 + 1);
}
lint Mininit(lint start, lint end, lint node)
{
    if (start == end)
        return Mlintree[node] = start;

    lint mid = (start + end) / 2;

    lint Leftidx = Mininit(start, mid, node * 2);
    lint Rightidx = Mininit(mid + 1, end, node * 2 + 1);

    if(v[Leftidx]<v[Rightidx])
        return Mlintree[node]=Leftidx;
    else
        return Mlintree[node]=Rightidx; 
}
lint Sum(lint start,lint end,lint node,lint left,lint right)
{
    if(right<start||end<left)
        return 0;
    if(left<=start&&end<=right)
        return Sumtree[node];

    lint mid=(start+end)/2;

    return Sum(start,mid,node*2,left,right)+Sum(mid+1,end,node*2+1,left,right);
}
lint Min(lint start,lint end,lint node,lint left,lint right)
{
    if(right<start||end<left)
        return 1e9;
    if(left<=start&&end<=right)
        return Mlintree[node];

    lint mid=(start+end)/2;

    lint Leftidx=Min(start,mid,node*2,left,right);
    lint Rightidx=Min(mid+1,end,node*2+1,left,right);

    if(Leftidx==1e9)
        return Rightidx;
    else if(Rightidx==1e9)
        return Leftidx;

    if(v[Leftidx]<v[Rightidx])
        return Leftidx;
    else
        return Rightidx;
}

void Divide(lint l,lint r)
{
    if(l>r)
        return;
    
    lint temp=Min(1,n,1,l,r);

    res=max(res,(v[temp]*Sum(1,n,1,l,r)));

    Divide(l,temp-1);
    Divide(temp+1,r);
    
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    Sumtree = vector<lint>(4 * (n + 1));
    Mlintree = vector<lint>(4 * (n + 1));
    v = vector<lint>(n + 1);
    for (lint i = 1; i <= n; i++)
        cin >> v[i];
    
    Suminit(1,n,1);
    Mininit(1,n,1);
    Divide(1,n);

    cout<<res;
    return 0;
}