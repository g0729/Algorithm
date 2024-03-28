#include <bits/stdc++.h>
using namespace std;
#define MAX 50
int MAP[MAX][MAX];
int cMAP[MAX][MAX];
bool sel[10];
int n, k;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int rres = 25000;
vector<pair<int, int>> vir;

void reset()
{
    for (int i = 0; i < n; i++)
    {
        for (int q = 0; q < n; q++)
        {
            cMAP[i][q] = 0;
        }
    }
}
int bfs()
{
    queue<pair<int, int>> q;
    for (int i = 0; i < vir.size(); i++)
    {
        if (sel[i])
        {
           int x=vir[i].first;
           int y=vir[i].second;
           q.push({x,y});
           cMAP[x][y]=1;
        }
    }

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (cMAP[nx][ny]!=0)
                continue;
            if(MAP[nx][ny]==1)
            continue;
            q.push({nx, ny});
            cMAP[nx][ny] = cMAP[x][y] + 1;
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int q = 0; q < n; q++)
        {
            if (cMAP[i][q] == 0)
            {
                if (MAP[i][q] != 1)
                {
                    return 25000;
                }
            }
            else
            {
                res = max(res, cMAP[i][q]);
            }
        }
    }
    return res-1;
}
void dfs(int idx, int cnt)
{
    if (cnt == k)
    {
        reset();
        int temp = bfs();
        rres = min(rres, temp);
    
        return;
    }
    for (int i = idx; i < vir.size(); i++)
    {
        if (sel[i])
            continue;
        int x = vir[i].first;
        int y = vir[i].second;
        sel[i] = true;
        dfs(i, cnt + 1);
        sel[i] = false;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        for (int q = 0; q < n; q++)
        {
            cin >> MAP[i][q];
            if (MAP[i][q] == 2)
            {
                vir.push_back({i, q});
            }
        }
    }
    dfs(0, 0);
    if(rres==25000)
    cout<<"-1";
    else
    cout << rres;
}