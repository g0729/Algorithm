#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000
vector<int> tree(4 * (MAX + 1));
vector<int> leftArr(MAX + 1);
vector<int> rightArr(MAX + 1);
vector<int> v(MAX + 1);

int update(int start, int end, int node, int idx)
{
    if (idx < start || idx > end)
        return tree[node];
    if (start == end)
        return tree[node] += 1;

    int mid = (start + end) / 2;

    return tree[node] = update(start, mid, node * 2, idx) + update(mid + 1, end, node * 2 + 1, idx);
}

int sum(int start, int end, int node, int left, int right)
{
    if (right < start || left > end)
        return 0;
    if (left <= start && end <= right)
        return tree[node];

    int mid = (start + end) / 2;

    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    for (int i = 1; i <= n; i++)
    {
        leftArr[i] = sum(1, n, 1, v[i] + 1, n);
        update(1, n, 1, v[i]);
    }
    tree = vector<int>(4 * (MAX + 1));

    for (int i = n; i > 0; i--)
    {
        rightArr[i] = sum(1, n, 1, 1, v[i] - 1);
        update(1, n, 1, v[i]);
    }

    ll ans = 0;

    for (int i = 1; i <= n; i++)
    {
        ans += (ll)leftArr[i] * rightArr[i];
    }

    cout << ans;
    return 0;
}