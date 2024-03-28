#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

vector<pair<int, int>> v[20001];
int Dist[20001];
int start;

void Dijkstar()
{
    priority_queue<pair<int, int>> pq;
    Dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        for (int i = 0; i < v[cur].size(); i++)
        {
            int next = v[cur][i].first;
            int nCost = v[cur][i].second;

            if (Dist[next] > cost + nCost)
            {
                Dist[next] = cost + nCost;
                pq.push({-Dist[next], next});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int ver, edg;
    cin >> ver >> edg >> start;

    for (int i = 0; i < edg; i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        v[a].push_back({b, cost});
    }

    for (int i = 1; i <= ver; i++)
    {
        Dist[i] = INF;
    }

    Dijkstar();

    for (int i = 1; i <= ver; i++)
    {
        if (Dist[i] == INF)
            cout << "INF\n";
        else
            cout << Dist[i] << "\n";
    }

    return 0;
}