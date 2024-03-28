#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
#define MOD 1000000007
vector<int> tree;
vector<int> v;

int init(int start,int end,int node)
{
    if(start==end)
        return tree[node]=v[start];
    
    int mid=(start+end)/2;

    return tree[node]=init(start,mid,node*2)+init(mid+1,end,node*2+1);
}
int Search(int start,int end,int node,int val)
{
    if(start==end)
        return start;

    int mid=(start+end)/2;

    if(tree[node*2]>=val)
        return Search(start,mid,node*2,val);
    else
        return Search(mid+1,end,node*2+1,val-tree[node*2]);
}
int update(int start,int end,int node ,int idx,int val)
{
    if(idx<start||idx>end)
        return tree[node];
    if(start==end)
        return tree[node]+=val;
    
    int mid=(start+end)/2;

    return tree[node]=update(start,mid,node*2,idx,val)+update(mid+1,end,node*2+1,idx,val);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    tree = vector<int>(4 * (n + 1));
    v = vector<int>(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> v[i];

    init(1,n,1);
    int m;
    cin>>m;

    for (int i = 0; i < m; i++)
    {
        int a,b,c;
        cin>>a;
        if(a==1)
        {
            cin>>b>>c;
            update(1,n,1,b,c);
        }
        else
        {
            cin>>b;
            cout<<Search(1,n,1,b)<<"\n";
        }
    }
    
    return 0;
}