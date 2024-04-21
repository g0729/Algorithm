#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
struct Fint
{
    int a, b, c, d;
    Fint(int a, int b, int c, int d) : a(a), b(b), c(c), d(d){};
};
vector<Fint> danger;
vector<Fint> death;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool check(Fint &cor, int &x, int &y)
{
    if ((cor.a <= x && x <= cor.c) && (cor.b <= y && y <= cor.d))
        return true;
    return false;
}
int bfs()
{
    deque<pair<int, int>> dq;
    vector<vector<int>> dist(501, vector<int>(501, 1e9));
    dq.push_back({0, 0});
    dist[0][0] = 0;

    while (!dq.empty())
    {
        pair<int, int> now = dq.front();
        dq.pop_front();

        if (now.first == 500 && now.second == 500)
            return dist[500][500];

        for (int i = 0; i < 4; i++)
        {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];

            if (nx < 0 || nx > 500 || ny < 0 || ny > 500)
                continue;

            bool flag = true;
            for (int j = 0; j < death.size(); j++)
            {
                if (check(death[j], nx, ny))
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
                continue;
            int zone = 0;
            for (int j = 0; j < danger.size(); j++)
            {
                if (check(danger[j], nx, ny))
                {
                    zone = 1;
                    break;
                }
            }

            if (!zone)
            {
                if (dist[nx][ny] > dist[now.first][now.second])
                {
                    dist[nx][ny] = dist[now.first][now.second];
                    dq.push_front({nx, ny});
                }
            }
            else
            {
                if (dist[nx][ny] > dist[now.first][now.second] + 1)
                {
                    dist[nx][ny] = dist[now.first][now.second] + 1;
                    dq.push_back({nx, ny});
                }
            }
        }
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b, c, d;
        vector<int> temp_x(2);
        vector<int> temp_y(2);
        cin >> a >> b >> c >> d;
        temp_x[0] = a;
        temp_x[1] = c;
        temp_y[0] = b;
        temp_y[1] = d;
        sort(temp_x.begin(), temp_x.end());
        sort(temp_y.begin(), temp_y.end());

        danger.push_back(Fint(temp_x[0], temp_y[0], temp_x[1], temp_y[1]));
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c, d;
        vector<int> temp_x(2);
        vector<int> temp_y(2);
        cin >> a >> b >> c >> d;
        temp_x[0] = a;
        temp_x[1] = c;
        temp_y[0] = b;
        temp_y[1] = d;
        sort(temp_x.begin(), temp_x.end());
        sort(temp_y.begin(), temp_y.end());

        death.push_back(Fint(temp_x[0], temp_y[0], temp_x[1], temp_y[1]));
    }

    cout << bfs();
    return 0;
}