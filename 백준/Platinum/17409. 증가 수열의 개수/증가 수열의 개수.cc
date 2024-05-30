#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

vector<vector<ll>> tree(11, vector<ll>(4 * (MAX + 1)));
vector<ll> v(MAX);
ll update(int start, int end, int node, int idx, int val, int num)
{
    if (idx < start || idx > end)
        return tree[num][node];
    if (start == end)
    {
        tree[num][node] = (tree[num][node] + val) % MOD;
        return tree[num][node];
    }

    int mid = (start + end) / 2;

    return tree[num][node] = (update(start, mid, node * 2, idx, val, num) + update(mid + 1, end, node * 2 + 1, idx, val, num))%MOD;
}

ll sum(int start, int end, int node, int left, int right, int num)
{
    if (right < start || left > end)
        return 0;
    if (left <= start && end <= right)
        return tree[num][node];

    int mid = (start + end) / 2;

    return (sum(start, mid, node * 2, left, right, num) + sum(mid + 1, end, node * 2 + 1, left, right, num))%MOD;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++)
    {
        update(1, MAX, 1, v[i], 1, 1);

        for (int j = 2; j <= k; j++)
        {
            ll temp = sum(1, MAX, 1, 1, v[i] - 1, j - 1);

            update(1, MAX, 1, v[i], temp, j);
        }
    }

    cout << sum(1, MAX, 1, 1, MAX, k);

    return 0;
}