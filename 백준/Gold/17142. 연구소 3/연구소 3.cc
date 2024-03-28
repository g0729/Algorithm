#include <bits/stdc++.h>
using namespace std;
#define MAX 1e5

int n, m;
int MAP[50][50];
int CMAP[50][50];
bool visited[50][50];
vector<pair<int, int>> virus;
bool choose[10];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int res = 1e4;
bool zero;
void copy()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            CMAP[i][j] = MAX;
        }
    }

    for (int i = 0; i < virus.size(); i++)
    {
        if (choose[i])
        {
            CMAP[virus[i].first][virus[i].second] = 0;
        }
    }
}
void bfs()
{
    queue<pair<int, int>> q;

    for (int i = 0; i < virus.size(); i++)
    {
        if (choose[i])
        {
            q.push(virus[i]);
        }
    }

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        visited[x][y] = true;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (visited[nx][ny] == true)
                continue;
            if (MAP[nx][ny] == 1)
                continue;
            CMAP[nx][ny] = min(CMAP[nx][ny], CMAP[x][y] + 1);
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
}
void select(int start, int cnt)
{
    if (cnt == m)
    {
        copy();
        bfs();
        memset(visited, false, sizeof(visited));
        int temp = 0;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (CMAP[i][j]==MAX&&MAP[i][j]==0)
                    return;
                if(MAP[i][j]==0)
                temp=max(temp,CMAP[i][j]);
            }
        }


        zero=true;
        res=min(res,temp);
     
    }
    else
    {
        for (int i = start; i < virus.size(); i++)
        {
            if (choose[i])
                continue;

            choose[i] = true;
            select(i, cnt + 1);
            choose[i] = false;
        }
    }
}
int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> MAP[i][j];
            if (MAP[i][j] == 2)
            {
                virus.push_back({i, j});
            }
        }
    }
    bool zerocheck = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (MAP[i][j] == 0)
                zerocheck = true;
        }
    }

    if (!zerocheck)
    {
        cout << "0";
        return 0;
    }

    select(0, 0);

    if (!zero)
        cout << "-1";
    else
        cout << res;
}