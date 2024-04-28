#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int n, m;
vector<string> MAP;
bool visited[1000][1000];
bool finished[1000][1000];
int ans = 0;
void dfs(int x, int y)
{
    visited[x][y] = true;
    int nx = x, ny = y;
    if (MAP[x][y] == 'D')
        nx += 1;
    else if (MAP[x][y] == 'U')
        nx -= 1;
    else if (MAP[x][y] == 'L')
        ny -= 1;
    else
        ny += 1;
    if (!visited[nx][ny])
        dfs(nx, ny);
    else if (!finished[nx][ny])
        ans++;
    finished[x][y] = true;
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
            if (!finished[i][j])
                dfs(i, j);
        }
    }

    cout << ans;
    return 0;
}