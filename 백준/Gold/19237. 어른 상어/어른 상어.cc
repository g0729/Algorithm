#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

struct shark
{
    int my_num;
    int dir;
    pair<int, int> loc;
    vector<vector<int>> move;
};
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
vector<shark> sharks;
vector<vector<int>> MAP;
vector<vector<pair<int, int>>> smell_map;
int n, m, k;

void smell_emit(int time)
{
    for (int i = 0; i < sharks.size(); i++)
    {
        int x, y, my_num;
        x = sharks[i].loc.first;
        y = sharks[i].loc.second;
        my_num = sharks[i].my_num;

        smell_map[x][y] = {my_num, time};
    }
}

void move(int time)
{
    vector<shark> temp_sharks;
    for (int i = 0; i < sharks.size(); i++)
    {
        int x, y, dir, my_num;
        x = sharks[i].loc.first;
        y = sharks[i].loc.second;
        dir = sharks[i].dir;
        my_num = sharks[i].my_num;
        bool flag = true;
        bool is_deleted = false;
        for (int j = 0; j < 4; j++)
        {
            int nx = x + dx[sharks[i].move[dir][j]];
            int ny = y + dy[sharks[i].move[dir][j]];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (time - smell_map[nx][ny].second >= k)
                smell_map[nx][ny] = {0, 0};

            if (smell_map[nx][ny].first != 0)
                continue;

            if (MAP[nx][ny] != 0)
            {
                MAP[x][y] = 0;
                is_deleted = true;
                break;
            }
            flag = false;
            sharks[i].loc = {nx, ny};
            sharks[i].dir = sharks[i].move[dir][j];
            MAP[x][y] = 0;
            MAP[nx][ny] = my_num;
            temp_sharks.push_back(sharks[i]);
            break;
        }

        if (flag && !is_deleted)
        {
            for (int j = 0; j < 4; j++)
            {
                int nx = x + dx[sharks[i].move[dir][j]];
                int ny = y + dy[sharks[i].move[dir][j]];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;
                if (smell_map[nx][ny].first == my_num)
                {
                    sharks[i].loc = {nx, ny};
                    sharks[i].dir = sharks[i].move[dir][j];
                    MAP[x][y] = 0;
                    MAP[nx][ny] = my_num;
                    temp_sharks.push_back(sharks[i]);
                    break;
                }
            }
        }
    }
    sharks = temp_sharks;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    sharks = vector<shark>(m);
    MAP = vector<vector<int>>(n, vector<int>(n));
    smell_map = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> MAP[i][j];
            if (MAP[i][j] != 0)
            {
                sharks[MAP[i][j] - 1].loc = {i, j};
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        sharks[i].my_num = i + 1;
        sharks[i].dir = a - 1;
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            vector<int> temp;
            for (int k = 0; k < 4; k++)
            {
                int a;
                cin >> a;
                temp.push_back(a - 1);
            }
            sharks[i].move.push_back(temp);
        }
    }

    for (int t = 1; t <= 1000; t++)
    {
        smell_emit(t);
        move(t);
        if (sharks.size() == 1)
        {
            cout << t << endl;
            return 0;
        }
    }
    cout << "-1";

    return 0;
}