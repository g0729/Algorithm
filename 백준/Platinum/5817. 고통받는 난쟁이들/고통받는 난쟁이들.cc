#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 200000

vector<int> MinTree(4 * (MAX + 1));
vector<int> MaxTree(4 * (MAX + 1));
vector<int> v(MAX + 1);
vector<int> arr(MAX + 1);
int n, m;

int Mininit(int start,int end,int node)
{
    if(start==end)
        return MinTree[node]=v[start];

    int mid=(start+end)/2;
    
    return MinTree[node]=min(Mininit(start,mid,2*node),Mininit(mid+1,end,node*2+1));
}
int Maxinit(int start,int end,int node)
{
    if(start==end)
        return MaxTree[node]=v[start];
        
    int mid=(start+end)/2;
    
    return MaxTree[node]=max(Maxinit(start,mid,2*node),Maxinit(mid+1,end,node*2+1));
}
int Max(int start,int end,int node,int left,int right)
{
    if(right<start||left>end)
        return 0;
    if(left<=start&&end<=right)
        return MaxTree[node];

    int mid=(start+end)/2;

    return max(Max(start,mid,2*node,left,right),Max(mid+1,end,node*2+1,left,right));
}


int Min(int start,int end,int node,int left,int right)
{
    if(right<start||left>end)
        return 1e9;
    
    if(left<=start&&end<=right)
        return MinTree[node];
    
    int mid=(start+end)/2;

    return min(Min(start,mid,2*node,left,right),Min(mid+1,end,node*2+1,left,right));
}
int MaxUpdate(int start,int end,int node,int idx,int val)
{
    if(idx<start||idx>end)
        return MaxTree[node];
    if(start==end)
        return MaxTree[node]=val;
    int mid=(start+end)/2;

    return MaxTree[node]=max(MaxUpdate(start,mid,2*node,idx,val),MaxUpdate(mid+1,end,node*2+1,idx,val));
}
int MinUpdate(int start,int end,int node,int idx,int val)
{
    if(idx<start||idx>end)
        return MinTree[node];
    if(start==end)
        return MinTree[node]=val;
    int mid=(start+end)/2;

    return MinTree[node]=min(MinUpdate(start,mid,2*node,idx,val),MinUpdate(mid+1,end,node*2+1,idx,val));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin>>a;
        arr[i]=a;
        v[a]=i;
    }
    Maxinit(1,n,1);
    Mininit(1,n,1);
    for (int i = 0; i < m; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1)
        {
            MaxUpdate(1,n,1,arr[b],c);
            MaxUpdate(1,n,1,arr[c],b);
            MinUpdate(1,n,1,arr[b],c);
            MinUpdate(1,n,1,arr[c],b);
            swap(arr[b],arr[c]);
        }
        else
        {
            int temp,temp2;
            temp=min(b,c);
            temp2=max(b,c);
            int MinIdx=Min(1,n,1,temp,temp2);
            int MaxIdx=Max(1,n,1,temp,temp2);
            if(MaxIdx-MinIdx==c-b)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
    
    return 0;
}