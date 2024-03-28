#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

vector<int> Maxtree;
vector<int> Mintree;

int Maxinit(int start, int end, int node)
{
    if (start == end)
        return Maxtree[node] = start;

    int mid = (start + end) / 2;

    return Maxtree[node]=max(Maxinit(start,mid,node*2),Maxinit(mid+1,end,node*2+1));
}

int Mininit(int start,int end,int node)
{
    if(start==end)
        return Mintree[node]=start;
    
    int mid=(start+end)/2;

    return Mintree[node]=min(Mininit(start,mid,node*2),Mininit(mid+1,end,node*2+1));
}
int Minupdate(int start,int end,int node,int idx,int val)
{
    if(idx<start||idx>end)
        return Mintree[node];

    if(start==end)
        return Mintree[node]=val;

    int mid=(start+end)/2;

    return Mintree[node]=min(Minupdate(start,mid,node*2,idx,val),Minupdate(mid+1,end,node*2+1,idx,val));
}
int Maxupdate(int start,int end,int node,int idx,int val)
{
    if(idx<start||idx>end)
        return Maxtree[node];

    if(start==end)
        return Maxtree[node]=val;

    int mid=(start+end)/2;

    return Maxtree[node]=max(Maxupdate(start,mid,node*2,idx,val),Maxupdate(mid+1,end,node*2+1,idx,val));
}
int Min(int start,int end,int node,int left,int right)
{
    if(right<start||left>end)
        return 1e9;
    if(left<=start&&end<=right)
        return Mintree[node];

    int mid=(start+end) /2;

    return min(Min(start,mid,node*2,left,right),Min(mid+1,end,node*2+1,left,right));
}
int Max(int start,int end,int node,int left,int right)
{
    if(right<start||left>end)
        return -1;
    if (left<=start&&end<=right)
        return Maxtree[node];

    int mid=(start+end)/2;

    return max(Max(start,mid,node*2,left,right),Max(mid+1,end,node*2+1,left,right));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int>v(n);
        Maxtree=vector<int>(4*n);
        Mintree=vector<int>(4*n);
        for (int i = 0; i < n; i++)
        {
            v[i]=i;
        }
        Mininit(0,n-1,1);
        Maxinit(0,n-1,1);
        for (int i = 0; i < m; i++)
        {
            int op,a,b;
            cin>>op>>a>>b;

            if(op==0)
            {
                Minupdate(0,n-1,1,v[a],b);
                Minupdate(0,n-1,1,v[b],a);
                Maxupdate(0,n-1,1,v[a],b);
                Maxupdate(0,n-1,1,v[b],a);
                swap(v[a],v[b]);
            }
            else
            {
                int Minidx=Min(0,n-1,1,a,b);
                int Maxidx=Max(0,n-1,1,a,b);
                if(Maxidx==b&&Minidx==a)
                    cout<<"YES";
                else
                    cout<<"NO";

                cout<<"\n";
            }
        }
        
    }
    return 0;
}