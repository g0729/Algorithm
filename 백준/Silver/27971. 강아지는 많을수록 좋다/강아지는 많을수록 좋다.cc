#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int n, m;
int dx[] = {0, 0};
vector<bool> closed(MAX + 1);

int bfs()
{
    queue<int> q;
    vector<bool> visited(n + 1);
    visited[0] = true;
    q.push(0);

    int level = 0;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            int now = q.front();
            q.pop();

            if (now == n)
                return level;

            for (int i = 0; i < 2; i++)
            {
                int next = now + dx[i];

                if (closed[next])
                    continue;
                if (visited[next])
                    continue;
                if (next > n)
                    continue;
                q.push(next);
                visited[next] = true;
            }
        }
        level++;
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> dx[0] >> dx[1];

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        for (int j = a; j <= b; j++)
            closed[j] = true;
    }

    cout << bfs();

    return 0;
}