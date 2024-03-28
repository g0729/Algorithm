#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

vector<int>v[100001];
bool visited[100001];
int order[100001];
int n,m,r;

void bfs()
{
    queue<int>q;
    q.push(r);
    visited[r]=true;
    int cnt=1;
    order[r]=1;
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        order[now]=cnt;
        cnt++;
        for (int i = 0; i < v[now].size(); i++)
        {
            int next=v[now][i];

            if(!visited[next])
            {
                visited[next]=true;
                q.push(next);
            }
        }
        
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

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
        sort(v[i].begin(),v[i].end());
    }
    
    bfs();

    for (int i = 1; i <= n; i++)
    {
        cout<<order[i]<<"\n";
    }
    
    return 0;
}