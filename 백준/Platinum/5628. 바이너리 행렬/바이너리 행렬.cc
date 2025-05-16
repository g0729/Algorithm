#pragma GCC optimize("-Ofast", "-funroll-all-loops")
#include <bits/stdc++.h>
// #define int long long
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 110, M = 1e6 + 10;
int n, m, d[N], st[N], vis[N], s, t, res, cnt, cost, maxf;
char g[N][N];
int head[N], nex[M], to[M], w[M], flow[M], tot;
inline void ade(int a, int b, int c, int d)
{
    to[++tot] = b;
    nex[tot] = head[a];
    w[tot] = d;
    flow[tot] = c;
    head[a] = tot;
}
inline void add(int a, int b, int c, int d)
{
    ade(a, b, c, d);
    ade(b, a, 0, -d);
}
inline int spfa()
{
    queue<int> q;
    q.push(s);
    memset(st, 0, sizeof st);
    memset(d, inf, sizeof d);
    d[s] = 0;
    while (q.size())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = head[u]; i; i = nex[i])
        {
            if (flow[i] && d[to[i]] > d[u] + w[i])
            {
                d[to[i]] = d[u] + w[i];
                if (!vis[to[i]])
                    q.push(to[i]), vis[to[i]] = 1;
            }
        }
    }
    return d[t] < inf;
}
int dfs(int x, int f)
{
    if (x == t)
        return cost += d[t] * f, f;
    st[x] = 1;
    int fl = 0;
    for (int i = head[x]; i && f; i = nex[i])
    {
        if (!st[to[i]] && flow[i] && d[to[i]] == d[x] + w[i])
        {
            int mi = dfs(to[i], min(flow[i], f));
            flow[i] -= mi, flow[i ^ 1] += mi, fl += mi, f -= mi;
        }
    }
    return fl;
}
inline int solve()
{
    cin >> n >> m;
    cnt = 0;
    t = n + m + 1;
    for (int i = 1; i <= n; i++)
        scanf("%s", g[i] + 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cnt += g[i][j] - '0';
    res = cnt;
    for (int y = 1; y <= m; y++)
    {
        if (y * n % m)
            continue;
        tot = 1;
        memset(head, 0, sizeof head);
        cost = 0;
        for (int i = 1; i <= n; i++)
            add(s, i, y, 0);
        for (int i = 1; i <= m; i++)
            add(i + n, t, y * n / m, 0);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                if (g[i][j] == '1')
                    add(i, j + n, 1, 0);
                else
                    add(i, j + n, 1, 1);
            }
        maxf = 0;
        while (spfa())
            maxf += dfs(s, inf);
        res = min(res, cnt - maxf + 2 * cost);
    }
    return res;
}
signed main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
        printf("Case %d: %d\n", i, solve());
    return 0;
}
