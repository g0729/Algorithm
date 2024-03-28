#include <bits/stdc++.h>
using namespace std;
int arr[10001];
int visited[10001];
int a, b, n;

void bfs()
{
    queue<int> q;
    q.push(a);
    visited[a] = 0;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        int temp = arr[now];
        for (int i = now + temp; i <= n; i += temp)
        {
            if (visited[i] > visited[now] + 1)
            {
                visited[i] = visited[now] + 1;
                q.push(i);
            }
        }
        for (int i = now - temp; i >= 1; i -= temp)
        {
            if (visited[i] > visited[now] + 1)
            {
                visited[i] = visited[now] + 1;
                q.push(i);
            }
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        visited[i] = 100000;
    }
    cin >> a >> b;
    if (a == b)
    {
        cout << "0";
        return 0;
    }

    bfs();

    if (visited[b] == 100000)
        cout << "-1";
    else
        cout << visited[b];
}