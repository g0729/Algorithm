#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000

int n;
char MAP[6][6];
vector<pair<int, int>> v;
vector<pair<int, int>> teacher;
bool flag = false;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool dfs(int x, int y)
{

    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x;
        int ny = y;
        while (1)
        {
            nx += dx[dir];
            ny += dy[dir];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                break;
            if (MAP[nx][ny] == 'O')
                break;
            if (MAP[nx][ny] == 'S')
                return false;
        }
    }
    return true;
}
bool check()
{
    for (int i = 0; i < teacher.size(); i++)
    {
        if (!dfs(teacher[i].first, teacher[i].second))
            return false;
    }

    return true;
}
void select(int cnt)
{
    if (cnt == 3)
    {
        if (check())
            flag = true;

        return;
    }

    for (int i = 0; i < v.size(); i++)
    {
        int x = v[i].first;
        int y = v[i].second;
        if (MAP[x][y] == 'X')
        {
            MAP[x][y] = 'O';
            select(cnt + 1);
            MAP[x][y] = 'X';
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> MAP[i][j];
            if (MAP[i][j] == 'X')
                v.push_back({i, j});
            else if (MAP[i][j] == 'T')
                teacher.push_back({i, j});
        }
    }

    select(0);

    cout << (flag ? "YES" : "NO");
    return 0;
}