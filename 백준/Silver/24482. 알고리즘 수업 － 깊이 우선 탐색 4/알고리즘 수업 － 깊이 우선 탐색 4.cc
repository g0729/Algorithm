#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

vector<int> v[100001];
int visited[100001];
int n,m,r;

void dfs(int now,int depth)
{
    for (int i = 0; i < v[now].size(); i++)
    {
        int next=v[now][i];

        if(visited[next]==-1)
        {
            visited[next]=depth+1;
            dfs(next,depth+1);
        }
    }
    
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(visited, 0xffffffff, sizeof(visited));

    cin>>n>>m>>r;

    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;

        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++)
    {
        sort(v[i].begin(),v[i].end(),greater<int>());
    }
    
    visited[r]=0;

    dfs(r,0);

    for (int i = 1; i <= n; i++)
    {
        cout<<visited[i]<<"\n";
    }
    
    return 0;
}