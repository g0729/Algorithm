#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
vector<vector<int>> MAP;
vector<vector<int>> Dist;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n;

int dij()
{
    priority_queue<pair<int, pair<int, int>>> pq;
    Dist[0][0] = MAP[0][0];
    pq.push({-Dist[0][0], {0, 0}});

    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            int ncost = cost + MAP[nx][ny];
            if (Dist[nx][ny] > ncost)
            {
                Dist[nx][ny] = ncost;
                pq.push({-ncost, {nx, ny}});
            }
        }
    }
    return Dist[n - 1][n - 1];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int idx = 1;
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        MAP = vector<vector<int>>(n, vector<int>(n));
        Dist = vector<vector<int>>(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> MAP[i][j];
                Dist[i][j] = INF;
            }
        }

        cout << "Problem " << idx << ": " << dij() << "\n";
        idx++;
    }
    return 0;
}