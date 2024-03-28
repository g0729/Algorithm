#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 250000

vector<vector<int>> tree(4 * MAX, vector<int>(10));
vector<int> lazy(4 * MAX);
vector<int> temp(10);
string s;

void init(int start, int end, int node)
{
    if (start == end)
    {
        tree[node][s[start - 1] - '0']++;
        return;
    }
    int mid = (start + end) / 2;

    init(start, mid, node * 2);
    init(mid + 1, end, node * 2 + 1);
    for (int i = 0; i < 10; i++)
    {
        tree[node][i] = tree[node * 2][i] + tree[node * 2 + 1][i];
    }
}

void cnt_shift(int node, int val)
{
    for (int i = 0; i < 10; i++)
    {
        temp[(i + val) % 10] = tree[node][i];
    }
    for (int i = 0; i < 10; i++)
    {
        tree[node][i] = temp[i];
    }
}
void update_lazy(int start, int end, int node)
{
    if (lazy[node])
    {
        cnt_shift(node, lazy[node]);
        if (start != end)
        {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}
void update(int start, int end, int node, int left, int right)
{
    update_lazy(start, end, node);
    if (left > end || right < start)
        return;
    if (left <= start && end <= right)
    {
        cnt_shift(node, 1);
        if (start != end)
        {
            lazy[node * 2] += 1;
            lazy[node * 2 + 1] += 1;
        }
        return;
    }

    int mid = (start + end) / 2;

    update(start, mid, node * 2, left, right);
    update(mid + 1, end, node * 2 + 1, left, right);
    for (int i = 0; i < 10; i++)
    {
        tree[node][i] = tree[node * 2][i] + tree[node * 2 + 1][i];
    }
}
int sum(int start, int end, int node, int left, int right)
{
    update_lazy(start, end, node);
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
    {
        int res = 0;
        for (int i = 1; i < 10; i++)
        {
            res += tree[node][i] * i;
        }
        return res;
    }

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
    cin >> s;

    init(1, n, 1);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        cout << sum(1, n, 1, a, b) << "\n";
        update(1, n, 1, a, b);
    }
    return 0;
}