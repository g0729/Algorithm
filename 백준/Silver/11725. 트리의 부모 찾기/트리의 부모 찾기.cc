#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
vector<int>v[100001];
bool visited[100001];
int parent[100001];
void bfs()
{
    queue<int>q;

    q.push(1);
    visited[1]=true;

    while(!q.empty())
    {
        int now=q.front();
        q.pop();

        for (int i = 0; i < v[now].size(); i++)
        {
            int next=v[now][i];

            if(visited[next])
            continue;

            visited[next]=true;
            q.push(next);
            parent[next]=now;
        }
        
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    for (int i = 0; i < n-1; i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    bfs();

    for (int i = 2; i <= n; i++)
    {
        cout<<parent[i]<<"\n";
    }
    
    return 0;
}