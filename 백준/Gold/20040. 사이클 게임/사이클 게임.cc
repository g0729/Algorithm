#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

vector<int> parent;

int find(int x)
{
    if (parent[x] == x)
        return x;
    else
        return parent[x] = find(parent[x]);
}

void merge(int x,int y)
{
    x=find(x);
    y=find(y);

    if(x==y)
        return;
    
    parent[y]=x;
}

bool isUnion(int x,int y)
{
    x=find(x);
    y=find(y);

    if(x==y)
        return true;
    else
        return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;

    parent=vector<int>(n);

    for (int i = 0; i < n; i++)
    {
        parent[i]=i;
    }
    
    int res=0;
    for (int i = 1; i <= m; i++)
    {
        int a,b;
        cin>>a>>b;

        if(isUnion(a,b))
        {
            if(res==0)
                res=i;
        }
        merge(a,b);
    }
    
    cout<<res;
    return 0;
}