#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 1000000

vector<int> tree((MAX + 1) * 4);
vector<int> v(MAX + 1);
int n, m;

int init(int start, int end, int node)
{
    if (start == end)
    {
        if (start == n)
            return tree[node] = 1;
        if (v[start] <= v[start + 1])
            return tree[node] = 1;
        else
            return tree[node] = 0;
    }

    int mid=(start+end)/2;

    return tree[node]=init(start,mid,node*2)+init(mid+1,end,node*2+1);
}

int Sum(int start,int end,int node,int left,int right)
{
    if(right<start||left>end)
        return 0;
    if(left<=start&&end<=right)
        return tree[node];

    int mid=(start+end)/2;

    return Sum(start,mid,node*2,left,right)+Sum(mid+1,end,node*2+1,left,right);
}

int Update(int start,int end,int node,int idx)
{
    if(idx<start||idx>end)
        return tree[node];
    if(start==end)
    {
        if(start==n)
            return 1;
        if(v[start]<=v[start+1])
            return tree[node]=1;
        else
            return tree[node]=0;
    }

    int mid=(start+end)/2;

    return tree[node]=Update(start,mid,node*2,idx)+Update(mid+1,end,node*2+1,idx);

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> v[i];
    
    init(1,n,1);

    for (int i = 0; i < m; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;

        if(a==1)
        {
            if(Sum(1,n,1,b,c-1)==(c-b))
                cout<<"CS204\n";
            else
                cout<<"HSS090\n";
        }
        else
        {
            swap(v[b],v[c]);
            Update(1,n,1,b);
            Update(1,n,1,b-1);
            Update(1,n,1,c);
            Update(1,n,1,c-1);
        }
    }
    
    return 0;
}