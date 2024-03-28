#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
#define MOD 1000000007
vector<int> tree;
vector<int> v;

int init(int start, int end, int node)
{
    if (start == end)
        return tree[node] = 1;

    int mid = (start + end) / 2;

    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}
int update(int start,int end,int node ,int idx)
{
    if(idx<start||idx>end)
        return tree[node];
    if(start==end)
        return tree[node]=0;

    int mid=(start+end)/2;

    return tree[node]=update(start,mid,node*2,idx)+update(mid+1,end,node*2+1,idx);
}
int Search(int start,int end,int node, int val)
{
    if(start==end)
        return start;
    
    int mid=(start+end)/2;

    if(tree[node*2+1]>val)
        return Search(mid+1,end,node*2+1,val);
    else
        return Search(start,mid,node*2,val-tree[node*2+1]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    tree = vector<int>((n + 1) * 4);
    v = vector<int>(n + 1);
    vector<int>res(n+1);

    init(1,n,1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    
    for(int i =n;i>=1;i--)
    {
        int temp=Search(1,n,1,v[i]);
        update(1,n,1,temp);
        res[temp]=i;
    }
    for (int i = 1; i <= n; i++)
    {
        cout<<res[i]<<" ";
    }
    
    return 0;
}