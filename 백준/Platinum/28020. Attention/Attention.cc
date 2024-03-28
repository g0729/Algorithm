#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

vector<pair<int, int>> arrA;
vector<int> arrB;
vector<int>tree(4*MAX);
vector<ll>tree2(4*MAX);
int update(int start,int end,int node,int idx)
{
    if(idx<start||idx>end)
        return tree[node];
    if(start==end)
        return tree[node]=1;

    int mid=(start+end)/2;

    return tree[node]=update(start,mid,node*2,idx)+update(mid+1,end,node*2+1,idx);
}

int sum(int start,int end,int node,int left,int right)
{
    if(right<start||left>end)
        return 0;
    if(left<=start&&end<=right)
        return tree[node];
    
    int mid=(start+end)/2;

    return sum(start,mid,node*2,left,right)+sum(mid+1,end,node*2+1,left,right);
}

ll update2(int start,int end,int node,int idx,int val)
{
    if(idx<start||idx>end)
        return tree2[node];
    if(start==end)
        return tree2[node]=val;

    int mid=(start+end)/2;

    return tree2[node]=update2(start,mid,node*2,idx,val)+update2(mid+1,end,node*2+1,idx,val);

}
ll sum2(int start,int end,int node,int left,int right)
{
    if(right<start||left>end)
        return 0;
    if(left<=start&&end<=right)
        return tree2[node];

    int mid=(start+end)/2;

    return sum2(start,mid,node*2,left,right)+sum2(mid+1,end,node*2+1,left,right);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arrA.push_back({a, i});
    }
    sort(arrA.begin(), arrA.end());

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arrB.push_back(arrA[a].second);
    }
    ll res=0;
    for (int i = 0; i < n; i++)
    {
        update(0,n-1,1,arrB[i]);
        int temp=sum(0,n-1,1,0,arrB[i]-1);
        update2(0,n-1,1,arrB[i],temp);
        res=res+sum2(0,n-1,1,0,arrB[i]-1);
    }
    
    if(res==0)
        cout<<"Attention is what I want";
    else
    {
        cout<<"My heart has gone to paradise\n";
        cout<<res;
    }
    return 0;
}