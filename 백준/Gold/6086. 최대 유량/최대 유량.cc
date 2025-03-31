#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
vector<vector<int>> capacity(52, vector<int>(52)), flow(52, vector<int>(52));

int bfs()
{
    int res = 0;
    while (1)
    {
        vector<int> parent(52, -1);
        queue<int> q;
        q.push(0);
        parent[0] = 0;
        while (!q.empty() && parent[25] == -1)
        {
            int now = q.front();
            q.pop();
            for (int next = 0; next < 52; next++)
            {
                if (capacity[now][next] - flow[now][next] > 0 && parent[next] == -1)
                {
                    q.push(next);
                    parent[next] = now;
                }
            }
        }

        if (parent[25] == -1)
            break;

        int amount = 1e9;
        int now = 25;
        while (now != 0)
        {
            amount = min(amount, capacity[parent[now]][now] - flow[parent[now]][now]);
            now = parent[now];
        }
        now = 25;
        while (now != 0)
        {
            flow[parent[now]][now] += amount;
            flow[now][parent[now]] -= amount;
            now = parent[now];
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
    int n;
    cin >> n;
    while (n--)
    {
        char a, b;
        int c;
        cin >> a >> b >> c;
        a = a - (a >= 'a' ? 'a' - 26 : 'A');
        b = b - (b >= 'a' ? 'a' - 26 : 'A');
        capacity[a][b] += c;
        capacity[b][a] += c;
    }

    cout << bfs();
    return 0;
}