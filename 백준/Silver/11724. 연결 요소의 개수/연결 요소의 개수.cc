#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 1001
#define INF 987654321

vector<int> v[MAX];
bool visited[MAX];

void bfs(int x)
{
    visited[x] = true;
    queue<int> q;
    q.push(x);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int i = 0; i < v[now].size(); i++)
        {
            int next = v[now][i];

            if (visited[next])
                continue;
            visited[next] = true;

            q.push(next);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bfs(i);
            res++;
        }
    }

    cout << res;
    return 0;
}