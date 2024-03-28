#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 6
int n;
char MAP[MAX][MAX];
int dx[] = {1, 0};
int dy[] = {0, 1};
int resMin = 1e9;
int resMax = -1e9;
void dfs(int x, int y, int num, char op)
{

    char now = MAP[x][y];
    if (now >= '0' && now <= '9')
    {
        now -= '0';
        int next = num;
        if (op == '+')
            next += now;
        else if (op == '-')
            next -= now;
        else
            next *= now;

        if (x == n - 1 && y == n - 1)
        {
            resMax = max(resMax, next);
            resMin = min(resMin, next);

            return;
        }
        for (int i = 0; i < 2; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= n || ny >= n)
                continue;
            dfs(nx, ny, next, op);
        }
    }
    else
    {
        for (int i = 0; i < 2; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= n || ny >= n)
                continue;
            dfs(nx, ny, num, now);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);
        for (int j = 0; j < n; j++)
        {
            MAP[i][j] = s[j * 2];
        }
    }

    dfs(0, 1, MAP[0][0] - '0', '0');
    dfs(1, 0, MAP[0][0] - '0', '0');

    cout << resMax << " " << resMin;
    return 0;
}