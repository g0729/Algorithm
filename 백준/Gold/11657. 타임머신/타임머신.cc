#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 501

ll dist[MAX];
int n, m;
vector<pair<int, pair<int, int>>> edge;
void Bellman()
{
    for (int i = 2; i <= n; i++)
        dist[i] = INF;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int from = edge[j].first;
            int to = edge[j].second.first;
            int cost = edge[j].second.second;

            if (dist[from] == INF)
                continue;
            if (dist[to] > dist[from] + cost)
            {
                dist[to] = dist[from] + cost;
                if (i == n - 1)
                {
                    cout << "-1";
                    return;
                }
            }
        }
    }
    for(int i=2 ; i<=n;i++)
    {
        if(dist[i]==INF)
            cout<<"-1";
        else
            cout<<dist[i];
        cout<<"\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back({a, {b, c}});
    }

    Bellman();
    return 0;
}