#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;
#define MAX 202
#define INF 987654321
int n;
vector<vector<int>> edges(MAX), capacity(MAX, vector<int>(MAX)), flow(MAX, vector<int>(MAX));

int max_flow()
{
    int res = 0;

    while (true)
    {
        queue<int> q;
        q.push(1);
        vector<int> parent(MAX, -1);

        while (!q.empty() && parent[n] == -1)
        {
            int cur = q.front();
            q.pop();
            for (auto next : edges[cur])
            {
                if (capacity[cur][next] - flow[cur][next] > 0 && parent[next] == -1)
                {
                    parent[next] = cur;
                    q.push(next);
                }
            }
        }

        if (parent[n] == -1)
            break;

        int min_flow = INF;
        for (int i = n; i != 1; i = parent[i])
            min_flow = min(min_flow, capacity[parent[i]][i] - flow[parent[i]][i]);

        for (int i = n; i != 1; i = parent[i])
        {
            flow[parent[i]][i] += min_flow;
            flow[i][parent[i]] -= min_flow;
        }

        res += min_flow;
    }

    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i < n; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int a;
            cin >> a;
            edges[i].push_back(a);
            edges[a].push_back(i);
            if (i == 1 || a == n)
                capacity[i][a] = 1;
            else
                capacity[i][a] = INF;
        }
    }

    cout << max_flow();

    return 0;
}