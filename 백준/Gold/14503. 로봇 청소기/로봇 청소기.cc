#include <bits/stdc++.h>
using namespace std;
#define MAX 50
int n, m;
int graph[MAX][MAX];
int head;
int cnt;
pair<int, int> loca;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
void f()
{
    while (1)
    {
        int y = loca.first;
        int x = loca.second;
        if (graph[y][x] == 0)
        {
            graph[y][x] = 2;
            cnt++;
        }
        bool check = true;
        for (int i = 1; i < 5; i++)
        {
            int heading = (head +4 -i) % 4;
            int nx = x + dx[heading];
            int ny = y + dy[heading];
            if (graph[ny][nx] == 0)
            {
                loca.first = ny;
                loca.second = nx;
                check = false;
                head = heading;
                break;
            }
        }
        if (check)
        {
            if (graph[y + dy[(head + 2) % 4]][x + dx[(head + 2) % 4]] == 1)
            {
                cout << cnt;
                exit(0);
            }
            else
            {
                loca.second = x + dx[(head + 2) % 4];
                loca.first = y + dy[(head + 2) % 4];
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    cin >> loca.first >> loca.second >> head;
    for (int i = 0; i < n; i++)
    {
        for (int q = 0; q < m; q++)
        {
            cin >> graph[i][q];
        }
    }
    f();
}