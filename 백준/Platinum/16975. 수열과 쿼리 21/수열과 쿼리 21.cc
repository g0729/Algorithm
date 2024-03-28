#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
#define MOD 1000000007

vector<lint> tree;
vector<lint> v;

void init(int start, int end, int node)
{
    if (start == end)
    {
        tree[node] = v[start];
        return;
    }
    int mid = (start + end) / 2;

    init(start, mid, node * 2);
    init(mid + 1, end, node * 2 + 1);
}
void update(int start, int end, int node, int left, int right, int val)
{
    if (right < start || left > end)
        return;

    if (left <= start && end <= right)
    {
        tree[node] += val;
        return;
    }

    int mid = (start + end) / 2;

    update(start, mid, node * 2, left, right, val);
    update(mid + 1, end, node * 2 + 1, left, right, val);
}
lint Search(int start, int end, int node, int idx, lint res)
{
    if (idx < start || idx > end)
        return 0;

    res += tree[node];

    if (start == end)
        return res;

    int mid = (start + end) / 2;

    return Search(start, mid, node * 2, idx, res) + Search(mid + 1, end, node * 2 + 1, idx, res);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    tree = vector<lint>(4 * n);
    v = vector<lint>(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    init(0, n - 1, 1);

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b, c, d;
        cin >> a;

        if (a == 1)
        {
            cin >> b >> c >> d;
            update(0, n - 1, 1, b - 1, c - 1, d);
        }
        else
        {
            cin >> b;
            cout << Search(0, n - 1, 1, b - 1, 0) << "\n";
        }
    }

    return 0;
}