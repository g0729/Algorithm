#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000
vector<int> tree((MAX + 1) * 4);
vector<int> v(MAX + 1);
int res;
int n;
int init(int start, int end, int node)
{
    if (start == end)
        return tree[node] = start;

    int mid = (start + end) / 2;

    int LeftIdx = init(start, mid, node * 2);
    int RightIdx = init(mid + 1, end, node * 2 + 1);

    if (v[LeftIdx] < v[RightIdx])
        return tree[node] = LeftIdx;
    else
        return tree[node] = RightIdx;
}

int Min(int start, int end, int node, int left, int right)
{
    if (right < start || end < left)
        return 1e9;
    if (left <= start && end <= right)
        return tree[node];

    int mid = (start + end) / 2;

    int LeftIdx = Min(start, mid, node * 2, left, right);
    int RightIdx = Min(mid + 1, end, node * 2 + 1, left, right);

    if (LeftIdx == 1e9)
        return RightIdx;
    else if (RightIdx == 1e9)
        return LeftIdx;

    if (v[LeftIdx] < v[RightIdx])
        return LeftIdx;
    else
        return RightIdx;
}

void divide(int l, int r)
{
    if (l > r)
        return;

    int temp = Min(1, n, 1, l, r);
    res = max(res, v[temp] * (r-l + 1));

    divide(l, temp - 1);
    divide(temp + 1, r);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> v[i];

    init(1, n, 1);
    divide(1, n);

    cout << res;
    return 0;
}