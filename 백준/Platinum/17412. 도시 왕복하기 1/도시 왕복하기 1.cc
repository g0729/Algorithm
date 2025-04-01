#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
vector<vector<int>> edges(401, vector<int>()), capacity(401, vector<int>(401)), flow(401, vector<int>(401));
int n, p;

int bfs()
{
    int res = 0;
    while (1)
    {
        queue<int> q;
        q.push(1);
        vector<int> parent(n + 1, -1);
        int amount = 1e9;

        while (!q.empty() && parent[2] == -1)
        {
            int cur = q.front();
            q.pop();

            for (auto next : edges[cur])
            {
                if (capacity[cur][next] - flow[cur][next] > 0 && parent[next] == -1)
                {
                    q.push(next);
                    parent[next] = cur;
                }
            }
        }

        if (parent[2] == -1)
            break;
        for (int i = 2; i != 1; i = parent[i])
            amount = min(amount, capacity[parent[i]][i] - flow[parent[i]][i]);

        for (int i = 2; i != 1; i = parent[i])
        {
            flow[parent[i]][i] += amount;
            flow[i][parent[i]] -= amount;
        }
        res += amount;
    }

    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> p;

    for (int i = 0; i < p; i++)
    {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
        capacity[a][b] = 1;
    }

    cout << bfs();
    return 0;
}