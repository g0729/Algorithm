#include <bits/stdc++.h>
using namespace std;
#define MAX 51
struct fireball
{

    int mass;
    int speed;
    int dir;
};
vector<fireball> v[MAX][MAX];
vector<fireball> cv[MAX][MAX];
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int n;
void move()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int t = 0; t < v[i][j].size(); t++)
            {
                int x = i;
                int y = j;
                int speed = v[i][j][t].speed;
                int dir = v[i][j][t].dir;
                int mass = v[i][j][t].mass;
                x = x + speed * dx[dir];
                y = y + speed * dy[dir];
                if (x < 0)
                {
                    x = x % n + n;
                }
                else
                {
                    x = x % n;
                    if (x == 0)
                        x = n;
                }
                if (y < 0)
                {
                    y = y % n + n;
                }
                else
                {
                    y = y % n;
                    if (y == 0)
                        y = n;
                }
                cv[x][y].push_back(v[i][j][t]);
            }
            v[i][j].clear();
        }
    }
}
void spread()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            if (cv[i][j].size() == 0)
                continue;
            if (cv[i][j].size() == 1)
            {
                v[i][j].push_back(cv[i][j][0]);
            }
            else
            {
                bool check = false;
                int firstdir = (cv[i][j][0].dir) % 2;
                int mass = 0;
                int speed = 0;
                for (int t = 0; t < cv[i][j].size(); t++)
                {
                    mass += cv[i][j][t].mass;
                    speed += cv[i][j][t].speed;
                    if (t != 0)
                    {
                        if ((cv[i][j][t].dir) % 2 != firstdir)
                        {
                            check = true;
                        }
                    }
                }
                mass = mass / 5;
                speed = speed / cv[i][j].size();
                if (mass == 0)
                {
                    cv[i][j].clear();
                    continue;
                }
                fireball temp;
                temp.mass = mass;
                temp.speed = speed;
                for (int t = 0; t < 4; t++)
                {
                    int dir;
                    if (check)
                    {
                        dir = t * 2 + 1;
                    }
                    else
                    {
                        dir = t * 2;
                    }
                    temp.dir = dir;
                    v[i][j].push_back(temp);
                }
            }
            cv[i][j].clear();
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        fireball temp;
        cin >> a >> b >> temp.mass >> temp.speed >> temp.dir;
        v[a][b].push_back(temp);
    }

    for (int i = 0; i < k; i++)
    {
        move();
        spread();
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int t = 0; t < v[i][j].size(); t++)
            {
                res += v[i][j][t].mass;
            }
        }
    }

    cout << res;
}
