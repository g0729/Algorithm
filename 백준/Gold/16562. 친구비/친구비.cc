#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int n, m, k;
vector<int> cost;
vector<int> parent;

int find(int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}
void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y)
    {
        if (cost[x] > cost[y])
            parent[x] = y;
        else
            parent[y] = x;
    }
}
bool isUnion(int x, int y)
{
    x = find(x);
    y = find(y);

    return x == y;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    cost = vector<int>(n + 1);
    parent = vector<int>(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
        parent[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }
    set<int> se;

    for (int i = 1; i <= n; i++)
    {
        se.insert(find(i));
    }

    int res = 0;

    for (auto it : se)
    {
        res += cost[it];
    }
    if (res <= k)
        cout << res;
    else
        cout << "Oh no";
    return 0;
}