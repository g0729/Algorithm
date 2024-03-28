#include<bits/stdc++.h>
using namespace std;
#define MAX 300
int graph[MAX][MAX];
bool visited[MAX][MAX];
int cgraph[MAX][MAX];
int n, m;
int year;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1 ,- 1 };
bool cntbfs(int a, int b)
{
    if (cgraph[a][b] == 0)
        return false;
    queue<pair<int, int>>q;
    q.push({ a,b });
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny<0 || ny>=m)
                continue;
            if (cgraph[nx][ny] == 0)
                continue;
            cgraph[nx][ny] = 0;
            q.push({ nx,ny });
        }
    }
      return true;
    
}
void reset()
{
    for (int i = 0; i < n; i++)
    {
        for (int q = 0; q < m; q++)
        {
            visited[i][q] = false;
        }
    }
}
void mapcopy()
{
    for (int i = 0; i < n; i++)
    {
        for (int q = 0; q < m; q++)
        {
            cgraph[i][q] = graph[i][q];
        }
    }
}
int melt(int a, int b)
{
    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        int x = a + dx[i];
        int y = b + dy[i];
        if (x < 0 || x >= n || y < 0 || y >= m)
            continue;
        if (cgraph[x][y] == 0)
            cnt++;
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int q = 0; q < m; q++)
        {
            cin >> graph[i][q];
        }
    }

    while (1)
    {
        int cnt = 0;
        mapcopy();
        for (int i = 0; i < n; i++)
        {
            for (int q = 0; q < m; q++)
            {
                if (cntbfs(i,q))
                {
                    cnt++;
                }
            }
        }
        if (cnt >= 2)
        {
            cout << year;
            exit(0);
        }
        if (cnt == 0)
        {
            cout << "0";
            exit(0);
        }
        mapcopy();
        for (int i = 0; i < n; i++)
        {
            for (int q = 0; q < m; q++)
            {
                if (graph[i][q] != 0)
                {
                    graph[i][q] = cgraph[i][q] - melt(i, q);
                    if (graph[i][q] < 0)
                        graph[i][q] = 0;
                }
            }
        }

        reset();
        year++;
    }

}