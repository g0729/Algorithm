#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;
vector<vector<char>> MAP;
bool visited[MAX][MAX];

struct Tint
{
    int a, b, c;
    Tint(int a, int b, int c) : a(a), b(b), c(c){};
};
vector<Tint> stars;
void ff(int x, int y, int len)
{
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int cx = x;
        int cy = y;
        for (int j = 0; j < len; j++)
        {
            cx += dx[i];
            cy += dy[i];
            visited[cx][cy] = true;
        }
    }
}
void f(int x, int y)
{
    int len = 1e5;
    for (int i = 0; i < 4; i++)
    {
        int cx = x;
        int cy = y;
        int cnt = 0;
        while (1)
        {
            cx += dx[i];
            cy += dy[i];
            if (cx < 0 || cx >= n || cy < 0 || cy >= m)
                break;
            if (MAP[cx][cy] != '*')
                break;
            cnt++;
        }
        len = min(len, cnt);
    }
    if (len >= 1)
    {
        stars.push_back(Tint(x + 1, y + 1, len));
        ff(x, y, len);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    MAP = vector<vector<char>>(n, vector<char>(m));

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
            if (MAP[i][j] == '*')
                f(i, j);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (MAP[i][j] == '*' && !visited[i][j])
            {
                cout << "-1";
                return 0;
            }
        }
    }

    cout << stars.size() << "\n";
    for (auto it : stars)
        cout << it.a << " " << it.b << " " << it.c << "\n";
    return 0;
}