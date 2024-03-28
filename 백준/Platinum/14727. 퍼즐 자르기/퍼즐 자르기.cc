#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
#define MOD 1000000007
vector<lint> v;
vector<lint> tree;
lint res = 0;
int n;
int init(int start, int end, int node)
{
    if (start == end)
        return tree[node] = start;

    int mid = (start + end) / 2;

    int Leftidx = init(start, mid, node * 2);
    int Rightidx = init(mid + 1, end, node * 2 + 1);

    if (v[Leftidx] > v[Rightidx])
        return tree[node] = Rightidx;
    else
        return tree[node] = Leftidx;
}

int Min(int start, int end, int node, int left, int right)
{
    if (right < start || left > end)
        return 1e9;
    if (left <= start && end <= right)
        return tree[node];

    int mid = (start + end) / 2;

    int Leftidx = Min(start, mid, node * 2, left, right);
    int Rightidx = Min(mid + 1, end, node * 2 + 1, left, right);

    if (Leftidx == 1e9)
        return Rightidx;
    else if (Rightidx == 1e9)
        return Leftidx;

    if (v[Leftidx] < v[Rightidx])
        return Leftidx;
    else
        return Rightidx;
}

void Divide(int l, int r)
{
    if (l > r)
        return;

    int temp = Min(1, n, 1, l, r);

    res = max(res, v[temp] * (r - l + 1));

    Divide(l, temp - 1);
    Divide(temp + 1, r);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    v = vector<lint>(n + 1);
    tree = vector<lint>((n + 1) * 4);
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    init(1, n, 1);
    Divide(1, n);

    cout << res;
    return 0;
}