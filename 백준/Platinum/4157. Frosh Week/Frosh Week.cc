#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
#define MOD 1000000007

vector<pair<int, int>> v;
vector<int> tree;

lint sum(int start, int end, int node, int left, int right)
{
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return tree[node];

    int mid = (start + end) / 2;

    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

int update(int start, int end, int node, int idx)
{
    if (idx < start || idx > end)
        return tree[node];

    if (start == end)
        return tree[node] = 1;

    int mid = (start + end) / 2;

    return tree[node] = update(start, mid, node * 2, idx) + update(mid + 1, end, node * 2 + 1, idx);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    v = vector<pair<int, int>>(n);
    tree = vector<int>(4 * n);

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v[i] = {a, i};
    }

    sort(v.begin(), v.end());

    lint res = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int now = v[i].second;

        res += sum(0, n - 1, 1, now, n - 1);
        update(0, n - 1, 1, now);
    }

    cout << res;

    return 0;
}