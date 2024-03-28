#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int graph[MAX][MAX];
int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    graph[x][y] = 1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x==n-1)
        return true;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (graph[nx][ny] == 1)
                continue;
            q.push({nx, ny});
            graph[nx][ny] = 1;
        }
    }
    return false;
}
int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int q = 0; q < m; q++)
        {
            scanf("%1d", &graph[i][q]);
        }
    }
    bool check = false;
    for (int i = 0; i < m; i++)
    {
        if(graph[0][i]==0)
        check = bfs(0, i);
        if(check)
        break;
    }
    if (check)
        cout << "YES";
    else
        cout << "NO";
}