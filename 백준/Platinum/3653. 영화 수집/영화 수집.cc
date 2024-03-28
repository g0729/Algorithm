#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
#define MOD 1000000007

vector<int> tree;
vector<int>pos;
int n,m;

int init(int start,int end,int node)
{
    if(start==end)
    {
        if(start<=m)
            return tree[node]=0;
        else
            return tree[node]=1;
    }

    int mid=(start+end)/2;

    return tree[node]=init(start,mid,node*2)+init(mid+1,end,node*2+1);
}
int update(int start,int end,int node,int idx,int val)
{
    if(idx<start||idx>end)
        return tree[node];
    if(start==end)
        return tree[node]+=val;

    int mid=(start+end)/2;

    return tree[node]=update(start,mid,node*2,idx,val)+update(mid+1,end,node*2+1,idx,val);
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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n>>m;
        tree = vector<int>(4 * (n+m));
        pos=vector<int>(n+m+1);
        init(1,n+m,1);
        for (int i = 1; i <= n; i++)
            pos[i]=i+m;
        int nowPos=m;
        for (int i = 0; i < m; i++)
        {
            int a;
            cin>>a;

            int temp=sum(1,n+m,1,1,pos[a]);
            cout<<temp-1<<" ";
            update(1,n+m,1,pos[a],-1);
            update(1,n+m,1,nowPos,1);
            pos[a]=nowPos;
            nowPos--;

        }
        cout<<"\n";
    }
    return 0;
}