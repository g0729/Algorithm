#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
vector<int> edges[500001];
int terminates;
int n, w;

void bfs()
{
    vector<bool> visited(n + 1);
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        bool flag = false;
        for (int i = 0; i < edges[now].size(); i++)
        {
            int next = edges[now][i];
            if (visited[next])
                continue;
            visited[next] = true;
            q.push(next);
            flag = true;
        }

        if (!flag)
            terminates++;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> w;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    bfs();
    cout.precision(6);
    cout << fixed << (double)w / terminates;
    return 0;
}