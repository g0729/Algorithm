#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {0, 1, 1, 1, 0, 0, 0, -1, -1, -1};
int dy[] = {0, -1, 0, 1, -1, 0, 1, -1, 0, 1};
int r, c;
vector<string> MAP;
pair<int, int> pos;
vector<pair<int, int>> crazy_bots;

bool act_1(int dir)
{
    int nx = pos.first + dx[dir];
    int ny = pos.second + dy[dir];

    if (MAP[nx][ny] == 'R')
        return false;

    MAP[pos.first][pos.second] = '.';
    MAP[nx][ny] = 'I';

    pos = {nx, ny};

    return true;
}

bool act_2()
{
    vector<vector<int>> cnt(r, vector<int>(c));

    for (auto bot : crazy_bots)
    {
        int n_dir;
        int dist = INF;
        for (int dir = 1; dir < 11; dir++)
        {
            int nx = bot.first + dx[dir];
            int ny = bot.second + dy[dir];
            int next_dist = abs(nx - pos.first) + abs(ny - pos.second);

            if (next_dist < dist)
            {
                dist = next_dist;
                n_dir = dir;
            }
        }
        int nx = bot.first + dx[n_dir];
        int ny = bot.second + dy[n_dir];

        if (MAP[nx][ny] == 'I')
            return false;

        MAP[bot.first][bot.second] = '.';
        cnt[nx][ny]++;
    }

    vector<pair<int, int>> n_bots;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (cnt[i][j] == 1)
            {
                n_bots.push_back({i, j});
                MAP[i][j] = 'R';
            }
        }
    }
    crazy_bots = n_bots;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        string s;
        cin >> s;
        MAP.push_back(s);
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (MAP[i][j] == 'I')
                pos = {i, j};
            else if (MAP[i][j] == 'R')
                crazy_bots.push_back({i, j});
        }
    }

    string s;
    cin >> s;

    for (int i = 1; i <= s.length(); i++)
    {
        int dir = s[i - 1] - '0';

        if (!act_1(dir) || !act_2())
        {
            cout << "kraj " << i;
            return 0;
        }
    }
    for (auto it : MAP)
        cout << it << "\n";

    return 0;
}