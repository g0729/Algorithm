#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 51

int MAP[MAX][MAX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool visited[MAX][MAX];
int n, l, r;
bool flag;
void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    vector<pair<int, int>> v;
    q.push({x, y});
    visited[x][y] = true;
    v.push_back({x, y});
    int sum = MAP[x][y];

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (visited[nx][ny])
                continue;
            int diff = abs(MAP[nx][ny] - MAP[x][y]);
            if (diff > r || diff < l)
                continue;

            sum += MAP[nx][ny];
            visited[nx][ny] = true;
            q.push({nx, ny});
            v.push_back({nx, ny});
        }
    }

    int temp = sum / v.size();

    if (v.size() >= 2)
        flag = true;
    for (int i = 0; i < v.size(); i++)
    {
        int x = v[i].first;
        int y = v[i].second;
        MAP[x][y] = temp;
    }

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> l >> r;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> MAP[i][j];
        }
    }

    int res = 0;
    while (1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j])
                    bfs(i, j);
            }
        }
        if (!flag)
            break;
        flag = false;
        memset(visited, false, sizeof(visited));
        res++;
    }
    cout << res;

    return 0;
}