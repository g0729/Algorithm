#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
#define MOD 1000000007
#define MAX 2000001
vector<int>tree(4*MAX);

int update(int start,int end,int node,int idx,int val)
{
    if(idx<start||idx>end)
        return tree[node];
    if(start==end)
        return tree[node]+=val;

    int mid=(start+end)/2;

    return tree[node]=update(start,mid,node*2,idx,val)+update(mid+1,end,node*2+1,idx,val);
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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;

    while(n--)
    {
        int a,b;
        cin>>a>>b;

        if(a==1)
            update(1,MAX,1,b,1);
        else
        {
            int temp=Search(1,MAX,1,b);
            update(1,MAX,1,temp,-1);
            cout<<temp<<"\n";
        }
    }
    return 0;
}
