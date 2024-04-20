#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 2100000
#define INF 987654321
int n, k;

int bfs()
{
    deque<int> dq;
    vector<int> dist(MAX, 1e9);
    dq.push_back(n);
    dist[n] = 0;
    while (!dq.empty())
    {
        int now = dq.front();
        dq.pop_front();

        if (now == k)
            return dist[k];

        int next = now * 2;

        if (next < MAX && dist[next] > dist[now])
        {
            dist[next] = dist[now];
            dq.push_front(next);
        }
        next = now - 1;
        if (next >= 0 && dist[next] > dist[now] + 1)
        {
            dist[next] = dist[now] + 1;
            dq.push_back(next);
        }
        next = now + 1;
        if (next < MAX && dist[next] > dist[now] + 1)
        {
            dist[next] = dist[now] + 1;
            dq.push_back(next);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    cout << bfs();
    return 0;
}