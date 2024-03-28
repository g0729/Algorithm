#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

vector<pair<int, int>> edge[MAX + 1];
int n, max_dist, max_node;
bool visited[MAX];
void dfs(int now, int val)
{
    visited[now] = true;
    if (val > max_dist)
    {
        max_dist = val;
        max_node = now;
    }
    for (int i = 0; i < edge[now].size(); i++)
    {
        int next = edge[now][i].first;
        int dist = edge[now][i].second;
        if (visited[next])
            continue;
        dfs(next, val + dist);
    }
}
int main()

{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a;
        while (1)
        {
            cin >> b;
            if (b == -1)
                break;
            cin >> c;
            edge[a].push_back({b, c});
            edge[b].push_back({a, c});
        }
    }
    dfs(1, 0);
    memset(visited, false, sizeof(visited));
    max_dist = 0;
    dfs(max_node, 0);

    cout << max_dist;
    return 0;
}