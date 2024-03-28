#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 500000

int n;
vector<int> v(MAX);
vector<int> tree(4 * MAX);
vector<int> lazy(4 * MAX);
int init(int start, int end, int node)
{
    if (start == end)
        return tree[node] = v[start];

    int mid = (start + end) / 2;

    return tree[node] = init(start, mid, node * 2) ^ init(mid + 1, end, node * 2 + 1);
}
void update_lazy(int start, int end, int node)
{
    if (lazy[node] != 0)
    {
        if ((end - start + 1) % 2 == 1)
            tree[node] ^= lazy[node];
        if (start != end)
        {
            lazy[node * 2] ^= lazy[node];
            lazy[node * 2 + 1] ^= lazy[node];
        }
        lazy[node] = 0;
    }
}

int update(int start, int end, int node, int left, int right, int val)
{
    update_lazy(start, end, node);

    if (left > end || right < start)
        return tree[node];
    if (left <= start && end <= right)
    {
        if ((end - start + 1) % 2 == 1)
            tree[node] ^= val;
        if (start != end)
        {
            lazy[node * 2] ^= val;
            lazy[node * 2 + 1] ^= val;
        }

        return tree[node];
    }
    int mid = (start + end) / 2;

    return tree[node] = update(start, mid, node * 2, left, right, val) ^ update(mid + 1, end, node * 2 + 1, left, right, val);
}
int sum(int start, int end, int node, int left, int right)
{
    update_lazy(start, end, node);

    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return tree[node];

    int mid = (start + end) / 2;

    return sum(start, mid, node * 2, left, right) ^ sum(mid + 1, end, node * 2 + 1, left, right);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

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
            update(0, n - 1, 1, b, c, d);
        }
        else
        {
            cin >> b >> c;
            cout << sum(0, n - 1, 1, b, c) << "\n";
        }
    }

    return 0;
}