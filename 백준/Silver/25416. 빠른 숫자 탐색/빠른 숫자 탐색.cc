#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
vector<vector<int>> v(5, vector<int>(5));
int bfs(int r, int c)
{

    queue<pair<int, int>> q;
    q.push({r, c});

    vector<vector<bool>> visited(5, vector<bool>(5, false));
    visited[r][c] = true;
    int res = 0;
    while (!q.empty())
    {
        int size = q.size();

        while (size--)
        {
            pair<int, int> cur = q.front();
            q.pop();

            if (v[cur.first][cur.second] == 1)
                return res;
            for (int i = 0; i < 4; i++)
            {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];

                if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
                    continue;

                if (v[nx][ny] == -1)
                    continue;
                if (visited[nx][ny])
                    continue;

                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
        res++;
    }

    return -1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> v[i][j];
        }
    }

    int r, c;
    cin >> r >> c;

    cout << bfs(r, c);
    return 0;
}