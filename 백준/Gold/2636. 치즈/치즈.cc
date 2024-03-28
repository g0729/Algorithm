#include<bits/stdc++.h>
using namespace std;
#define MAX 100
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int graph[MAX][MAX];
int res;
int cnt;
int n, m;
int visited[MAX][MAX];
int day;
bool bfs()
{
    cnt = 0;
    queue<pair<int,int>>q;
    q.push({ 0,0 });
    visited[0][0] = true;;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (visited[nx][ny] == true)
                continue;
            visited[nx][ny] = true;
            if (graph[nx][ny] == 0)
            {
                q.push({ nx,ny });
            }
            if (graph[nx][ny] == 1)
            {
                cnt++;
                graph[nx][ny] = 0;
            }
        }
    }
    
    if (cnt == 0)
        return false;
    else
    {
        res = cnt;
        return true;
    }
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
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int q = 0; q < m; q++)
        {
            cin >> graph[i][q];
        }
    }
    while (bfs())
    {
        reset();
        day++;
    }
    cout << day <<endl<< res;
}