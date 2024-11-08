#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;
vector<string> MAP;
bool visited[50][50][100];
int bfs(pair<int, int> start)
{
    queue<pair<pair<int, int>, bitset<6>>> q;
    q.push({start, bitset<6>(0)});
    visited[start.first][start.second][0] = true;

    int res = 1;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            pair<int, int> cur = q.front().first;
            bitset<6> keys = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;
                if (MAP[nx][ny] == '#')
                    continue;

                if (MAP[nx][ny] == '1')
                {
                    return res;
                }
                else if (MAP[nx][ny] == '.')
                {
                    if (visited[nx][ny][keys.to_ulong()])
                        continue;
                    q.push({{nx, ny}, keys});
                    visited[nx][ny][keys.to_ulong()] = true;
                }
                else if (MAP[nx][ny] >= 'a' && MAP[nx][ny] <= 'z')
                {
                    bitset<6> temp = keys;
                    temp[MAP[nx][ny] - 'a'] = 1;
                    if (visited[nx][ny][temp.to_ulong()])
                        continue;
                    q.push({{nx, ny}, temp});
                    visited[nx][ny][temp.to_ulong()] = true;
                }
                else if (MAP[nx][ny] >= 'A' && MAP[nx][ny] <= 'Z')
                {
                    if (visited[nx][ny][keys.to_ulong()])
                        continue;
                    if (keys[MAP[nx][ny] - 'A'] == 0)
                        continue;
                    q.push({{nx, ny}, keys});
                    visited[nx][ny][keys.to_ulong()] = true;
                }
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

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        MAP.push_back(s);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (MAP[i][j] == '0')
            {
                MAP[i][j] = '.';
                cout << bfs({i, j});
                return 0;
            }
        }
    }

    return 0;
}