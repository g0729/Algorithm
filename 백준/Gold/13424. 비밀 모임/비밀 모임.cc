#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, m;
vector<vector<pair<int, int>>> edges;

vector<int> dij(int start)
{
    priority_queue<pair<int, int>> pq;
    vector<int> dist(n + 1);

    pq.push({0, start});
    for (int i = 0; i < n + 1; i++)
        dist[i] = INF;
    dist[start] = 0;

    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost)
            continue;
        for (int i = 0; i < edges[cur].size(); i++)
        {
            int next = edges[cur][i].first;
            int ncost = edges[cur][i].second + cost;

            if (dist[next] > ncost)
            {
                dist[next] = ncost;
                pq.push({-ncost, next});
            }
        }
    }

    return dist;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        edges = vector<vector<pair<int, int>>>(n + 1, vector<pair<int, int>>(0));

        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;

            edges[a].push_back({b, c});
            edges[b].push_back({a, c});
        }

        vector<vector<int>> dists;

        for (int i = 1; i <= n; i++)
            dists.push_back(dij(i));

        int k;
        cin >> k;
        vector<int> members(k);

        for (int i = 0; i < k; i++)
        {
            cin >> members[i];
        }

        int min = 1e9;
        int idx;

        for (int i = 1; i <= n; i++)
        {
            int sum = 0;
            for (int j = 0; j < k; j++)
            {
                int member = members[j] - 1;
                sum += dists[member][i];
            }

            if (sum < min)
            {
                min = sum;
                idx = i;
            }
        }

        cout << idx << "\n";
    }

    return 0;
}