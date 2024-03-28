#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000

vector<int> tree(4 * MAX);
vector<bool> lazy(4 * MAX);
void update_lazy(int start, int end, int node)
{
    if (lazy[node])
    {
        tree[node] = (end - start + 1) - tree[node];
        if (start != end)
        {
            lazy[node * 2] = !lazy[node * 2];
            lazy[node * 2 + 1] = !lazy[node * 2 + 1];
        }
        lazy[node] = false;
    }
}

int update(int start, int end, int node, int left, int right)
{
    update_lazy(start, end, node);
    if (left > end || right < start)
        return tree[node];
    if (left <= start && end <= right)
    {
        if (start != end)
        {
            lazy[node * 2] = !lazy[node * 2];
            lazy[node * 2 + 1] = !lazy[node * 2 + 1];
        }
        return tree[node] = (end - start + 1) - tree[node];
    }

    int mid = (start + end) / 2;

    return tree[node] = update(start, mid, node * 2, left, right) + update(mid + 1, end, node * 2 + 1, left, right);
}

int sum(int start, int end, int node, int left, int right)
{
    update_lazy(start, end, node);
    if (left > end || right < start)
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

    int n, m;

    cin >> n >> m;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 0)
        {
            update(1, n, 1, b, c);
        }
        else
        {
            cout << sum(1, n, 1, b, c) << "\n";
        }
    }
    return 0;
}