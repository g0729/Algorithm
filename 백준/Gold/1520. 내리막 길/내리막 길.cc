#include <bits/stdc++.h>
using namespace std;
#define MAX 500
int graph[MAX][MAX];
int dp[MAX][MAX];
int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

int dfs(int x, int y)
{
    if(x==n-1&&y==m-1)
    return 1;
    if(dp[x][y]!=-1)
    return dp[x][y];
    dp[x][y]=0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m)
        {
            if (graph[nx][ny] < graph[x][y])
            {
                dp[x][y] += dfs(nx, ny);
            }
        }
    }
    return dp[x][y];
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
            dp[i][q] = -1;
        }
    }
    int res=dfs(0,0);
    cout<<res;
}