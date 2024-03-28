#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
int n, m;
bool visited[MAX];
int arr[MAX];
int bfs()
{
    queue<pair<int, int>> q;
    q.push({n, 0});
    arr[n] = -1;
    visited[n] = true;
    while (!q.empty())
    {
        int now = q.front().first;
        int time = q.front().second;
        q.pop();
        int next[3];
        next[0] = now - 1;
        next[1] = now + 1;
        next[2] = now * 2;
        for (int i = 0; i < 3; i++)
        {
            if (next[i] < 0 || next[i] > MAX)
                continue;
            if (visited[next[i]])
                continue;
            q.push({next[i], time + 1});
            visited[next[i]] = true;
            arr[next[i]] = now;
            if (next[i] == m)
                return time + 1;
            
        }
    }
    return 0;
}
void print(int parent)
{
    if (arr[parent] == -1)
        return;

    print(arr[parent]);
    cout << arr[parent] << " ";
}
int main()
{
    cin >> n >> m;
    int res = bfs();
    cout << res << "\n";
    print(m);
    cout << m;
}