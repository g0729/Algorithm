#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 50000

vector<ll> tree(4 * MAX);
vector<ll> tree2(4 * MAX);
ll update(int start, int end, int node, int idx, int val)
{
    if (idx < start || idx > end)
        return tree[node];
    if (start == end)
        return tree[node] += val;

    int mid = (start + end) / 2;

    return tree[node] = update(start, mid, node * 2, idx, val) + update(mid + 1, end, node * 2 + 1, idx, val);
}
ll update2(int start, int end, int node, int idx)
{
    if (idx < start || idx > end)
        return tree2[node];
    if (start == end)
        return tree2[node] += 1;

    int mid = (start + end) / 2;

    return tree2[node] = update2(start, mid, node * 2, idx) + update2(mid + 1, end, node * 2 + 1, idx);
}
ll sum(int start, int end, int node, int left, int right)
{
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return tree[node];

    int mid = (start + end) / 2;

    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}
ll sum2(int start, int end, int node, int left, int right)
{
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return tree2[node];

    int mid = (start + end) / 2;

    return sum2(start, mid, node * 2, left, right) + sum2(mid + 1, end, node * 2 + 1, left, right);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        update(0, MAX, 1, v[i].second, v[i].second);
        update2(0, MAX, 1, v[i].second);

        ll right = sum(0, MAX, 1, v[i].second + 1, MAX);
        right = right - (sum2(0, MAX, 1, v[i].second + 1, MAX) * v[i].second);
        ll left = sum(0, MAX, 1, 0, v[i].second - 1);
        left = sum2(0, MAX, 1, 0, v[i].second - 1) * v[i].second - left;
        res += (left + right) * v[i].first;
    }

    cout << res;

    return 0;
}