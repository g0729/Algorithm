#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 500000

vector<int> tree(4 * MAX);

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
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return tree[node];

    int mid = (start + end) / 2;

    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}
bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
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
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        v[i].first = i;
    }
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < n; i++)
    {
        int temp = sum(0, MAX, 1, 0, v[i].first);
        update(0, MAX, 1, v[i].first);
        cout << i - temp + 1 << "\n";
    }

    return 0;
}