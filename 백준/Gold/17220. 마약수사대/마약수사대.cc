#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m, res;
vector<vector<int>> edges(26, vector<int>());
vector<int> cnts(26);
vector<bool> visited(26);

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int i = 0; i < edges[now].size(); i++)
        {
            int next = edges[now][i];

            if (visited[next])
                continue;
            visited[next] = true;
            res++;
            q.push(next);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    vector<int> roots;
    for (int i = 0; i < m; i++)
    {
        char a, b;
        cin >> a >> b;
        edges[a - 'A'].push_back(b - 'A');
        cnts[b - 'A']++;
    }
    int t;
    cin >> t;
    while (t--)
    {
        char a;
        cin >> a;
        visited[a - 'A'] = true;
    }
    for (int i = 0; i < n; i++)
    {
        if (!cnts[i])
            roots.push_back(i);
    }

    for (int i = 0; i < roots.size(); i++)
    {
        if (visited[roots[i]])
            continue;
        bfs(roots[i]);
    }

    cout << res;
    return 0;
}