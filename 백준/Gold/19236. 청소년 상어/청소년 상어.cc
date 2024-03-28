#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
int res = 0;
vector<vector<pair<int, int>>> MAP(4, vector<pair<int, int>>(4));
void swap_fish(vector<pair<int, pair<int, int>>> &fishes, int target1, int target2)
{
    for (int i = 0; i < fishes.size(); i++)
    {
        if (fishes[i].first == target2)
        {
            pair<int, int> temp = fishes[i].second;
            fishes[i].second = fishes[target1].second;
            fishes[target1].second = temp;
            return;
        }
    }
}
bool cmp(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b)
{
    return a.first < b.first;
}
void dfs(int cnt, vector<vector<pair<int, int>>> curMAP, pair<pair<int, int>, int> shark)
{
    res = max(res, cnt);
    vector<pair<int, pair<int, int>>> fishes;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (curMAP[i][j].first == 0)
                continue;
            fishes.push_back({curMAP[i][j].first, {i, j}});
        }
    }
    sort(fishes.begin(), fishes.end(), cmp);

    for (int i = 0; i < fishes.size(); i++)
    {
        int x = fishes[i].second.first;
        int y = fishes[i].second.second;
        int dir = curMAP[x][y].second;
        for (int j = 0; j < 8; j++)
        {
            int ndir = (dir + j) % 8;
            int nx = x + dx[ndir];
            int ny = y + dy[ndir];

            if ((nx == shark.first.first && ny == shark.first.second) || nx < 0 || nx >= 4 || ny < 0 || ny >= 4)
                continue;
            swap_fish(fishes, i, curMAP[nx][ny].first);
            pair<int, int> temp = curMAP[x][y];
            temp.second = ndir;
            curMAP[x][y] = curMAP[nx][ny];
            curMAP[nx][ny] = temp;
            break;
        }
    }

    int x = shark.first.first;
    int y = shark.first.second;
    int dir = shark.second;
    while (1)
    {
        x += dx[dir];
        y += dy[dir];

        if (x < 0 || x >= 4 || y < 0 || y >= 4)
            break;
        if (curMAP[x][y].first == 0)
            continue;
        int ncnt = cnt + curMAP[x][y].first;
        int temp = curMAP[x][y].first;
        curMAP[x][y].first = 0;
        dfs(ncnt, curMAP, {{x, y}, curMAP[x][y].second});
        curMAP[x][y].first = temp;
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> MAP[i][j].first >> MAP[i][j].second;
            MAP[i][j].second--;
        }
    }
    int cnt = MAP[0][0].first;
    MAP[0][0].first = 0;
    dfs(cnt, MAP, {{0, 0}, MAP[0][0].second});

    cout << res;
    return 0;
}