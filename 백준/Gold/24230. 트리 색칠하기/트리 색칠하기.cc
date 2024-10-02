#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n;
int res = 0;
vector<int> v;
vector<int> edges[200001];
vector<bool> visited(200001);
void dfs(int cur, int parentColor)
{
    int nColor = parentColor;
    visited[cur] = true;
    if (parentColor != v[cur])
    {
        nColor = v[cur];
        res++;
    }

    for (int i = 0; i < edges[cur].size(); i++)
    {
        int next = edges[cur][i];
        if (!visited[next])
            dfs(edges[cur][i], nColor);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    v.push_back(0);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(1, 0);

    cout << res;
    return 0;
}