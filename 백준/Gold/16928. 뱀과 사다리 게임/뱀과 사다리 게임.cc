#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> ladder;
vector<pair<int, int>> snake;
int n, m;
int visited[101];
void bfs()
{
    queue<int> q;
    q.push({1});

    while (!q.empty())
    {
        bool check = false;
        int now = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (ladder[i].first == now)
            {
                if (visited[ladder[i].second] > visited[now] || visited[ladder[i].second] == 0)
                {
                    q.push(ladder[i].second);
                    visited[ladder[i].second] = visited[now];
                }
                check = true;
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (snake[i].first == now)
            {
                if (visited[snake[i].second] > visited[now] || visited[snake[i].second] == 0)
                {
                    q.push(snake[i].second);
                    visited[snake[i].second] = visited[now];
                }
                check = true;
                break;
            }
        }
        if (check)
            continue;
        for (int i = 1; i <= 6; i++)
        {
            if (now + i <= 100)
            {
                if (visited[now + i] > visited[now] + 1 || visited[now + i] == 0)
                {
                    q.push(now + i);
                    visited[now + i] = visited[now] + 1;
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        ladder.push_back({a, b});
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        snake.push_back({a, b});
    }

    bfs();
    cout << visited[100];
}