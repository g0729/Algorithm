#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int m, n;
int MAP[MAX][MAX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int bfs(int x, int y)
{
    int cnt = 0;
    queue<pair<int, int>> q;
    MAP[x][y] = 1;
    q.push({x, y});
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        cnt++;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;
            if (MAP[nx][ny] == 1)
                continue;
            MAP[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> v;
    int res = 0;
    cin >> m >> n;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = x1; i < x2; i++)
        {
            for (int j = y1; j < y2; j++)
            {
                MAP[j][i] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (MAP[i][j] == 0)
            {
                res++;
                int temp = bfs(i, j);
                v.push_back(temp);
            }
        }
    }

    sort(v.begin(),v.end());
    cout<<res<<endl;
    for (int i = 0; i < res; i++)
    {
        cout<<v[i]<<" ";
    }
    
}