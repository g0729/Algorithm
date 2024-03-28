#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
#define INF 987654321
char MAP[MAX][MAX];
int FireMAP[MAX][MAX];
bool visited[MAX][MAX];
int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
queue<pair<int, int>> fireq;
queue<tuple<int, int, int>> jq;
void firebfs()
{

    while (!fireq.empty())
    {
        int x = fireq.front().first;
        int y = fireq.front().second;   
        fireq.pop();
        for (int i = 0 ; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (MAP[nx][ny] == '#')
                continue;
            if(FireMAP[nx][ny]==INF)
            {
                fireq.push({nx,ny});
                FireMAP[nx][ny]=FireMAP[x][y]+1;
            }
        }
    }
}
int jbfs()
{
    while (!jq.empty())
    {
        int x = get<0>(jq.front());
        int y = get<1>(jq.front());
        int cnt = get<2>(jq.front());
        jq.pop();
        if(x==0||y==0||x==n-1||y==m-1)
        return cnt+1;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (MAP[nx][ny] =='#')
            continue;
            if(FireMAP[nx][ny]<=cnt+1)
            continue;
            if(visited[nx][ny])
            continue;
            visited[nx][ny]=true;
            jq.push({nx,ny,cnt+1});
        }
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int q = 0; q < m; q++)
        {
            cin >> MAP[i][q];
            FireMAP[i][q] = INF;
            if (MAP[i][q] == 'F')
            {
                FireMAP[i][q] = 0;
                fireq.push({i, q});
            }
            if (MAP[i][q] == 'J')
            {
                jq.push({i, q, 0});
                visited[i][q] = true;
            }
        }
    }
    firebfs();
    int res=jbfs();
    if(res==-1)
    cout<<"IMPOSSIBLE";
    else
    cout<<res;
}