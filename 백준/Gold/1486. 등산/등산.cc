#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

int n, m, t, d;
char MAP[25][25];
int dist[25][25][25][25];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int char_to_int(char &c)
{
    if (c >= 'A' && c <= 'Z')
        return c - 'A';
    else
        return c - 'a' + 26;
}
int cost_cal(char &src, char &dst)
{
    int a = char_to_int(src);
    int b = char_to_int(dst);

    if (a >= b)
        return 1;
    else
        return (b - a) * (b - a);
}
void dij(pair<int, int> start)
{
    dist[start.first][start.second][start.first][start.second] = 0;
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        int cost = -pq.top().first;
        pair<int, int> cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (abs(char_to_int(MAP[nx][ny]) - char_to_int(MAP[cur.first][cur.second])) > t)
                continue;
            int ncost = cost_cal(MAP[cur.first][cur.second], MAP[nx][ny]);

            if (dist[start.first][start.second][nx][ny] > ncost + cost)
            {
                dist[start.first][start.second][nx][ny] = ncost + cost;
                pq.push({-(ncost + cost), {nx, ny}});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> t >> d;

    memset(dist, 0b00111111, sizeof(dist));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> MAP[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dij({i, j});
        }
    }
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dist[0][0][i][j] + dist[i][j][0][0] <= d)
            {
                answer = max(answer, char_to_int(MAP[i][j]));
            }
        }
    }
    cout << answer;

    return 0;
}