#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int n, m;
int MAP[1001][1001];
int acc_sum[1001][1001];
bool visited[1001][1001];
int h, w, sr, sc, fr, fc;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isAccept(int x1, int y1, int x2, int y2)
{
    int blocks = blocks = acc_sum[x2][y2] - acc_sum[x2][y1 - 1] - acc_sum[x1 - 1][y2] + acc_sum[x1 - 1][y1 - 1];
    return blocks == 0;
}
bool isBorder(int x, int y)
{
    return (x >= 1 && x <= n && y >= 1 && y <= m);
}

int bfs()
{
    visited[sr][sc] = true;
    queue<pair<int, int>> q;
    q.push({sr, sc});
    int level = 0;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            pair<int, int> now = q.front();
            q.pop();
            if (now.first == fr && now.second == fc)
                return level;
            for (int i = 0; i < 4; i++)
            {
                int x1 = now.first + dx[i], y1 = now.second + dy[i];
                int x2 = x1 + h - 1, y2 = y1 + w - 1;
                if (!isBorder(x1, y1) || !isBorder(x2, y2))
                    continue;
                if (visited[x1][y1])
                    continue;
                if (!isAccept(x1, y1, x2, y2))
                    continue;
                visited[x1][y1] = true;
                q.push({x1, y1});
            }
        }
        level++;
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> MAP[i][j];
    cin >> h >> w >> sr >> sc >> fr >> fc;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            acc_sum[i][j] = acc_sum[i - 1][j] + acc_sum[i][j - 1] - acc_sum[i - 1][j - 1] + MAP[i][j];
        }
    }

    cout << bfs();
    return 0;
}