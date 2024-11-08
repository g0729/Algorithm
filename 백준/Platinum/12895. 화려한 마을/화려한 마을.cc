#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, t, q;
vector<bitset<30>> tree(4 * MAX, bitset<30>(1));
vector<bitset<30>> lazy(4 * MAX);

void update_lazy(int start, int end, int node)
{
    if (lazy[node] != 0)
    {
        tree[node] = lazy[node];
        if (start != end)
        {
            lazy[node * 2] = lazy[node];
            lazy[node * 2 + 1] = lazy[node];
        }
        lazy[node] = 0;
    }
}
bitset<30> update(int start, int end, int node, int left, int right, int value)
{
    update_lazy(start, end, node);

    if (left > end || right < start)
        return tree[node];

    if (left <= start && end <= right)
    {
        bitset<30> temp(0);
        temp[value] = 1;
        if (start != end)
        {
            lazy[node * 2] = temp;
            lazy[node * 2 + 1] = temp;
        }
        return tree[node] = temp;
    }
    int mid = (start + end) / 2;

    return tree[node] = update(start, mid, node * 2, left, right, value) | update(mid + 1, end, node * 2 + 1, left, right, value);
}
bitset<30> search(int start, int end, int node, int left, int right)
{
    update_lazy(start, end, node);
    if (left > end || right < start)
        return bitset<30>(0);
    if (left <= start && end <= right)
        return tree[node];

    int mid = (start + end) / 2;

    return search(start, mid, node * 2, left, right) | search(mid + 1, end, node * 2 + 1, left, right);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> t >> q;

    while (q--)
    {
        char op;
        int x, y, z;
        cin >> op;
        cin >> x >> y;
        if (x > y)
            swap(x, y);
        if (op == 'C')
        {
            cin >> z;
            update(1, n, 1, x, y, z - 1);
        }
        else if (op == 'Q')
        {
            bitset<30> res = search(1, n, 1, x, y);
            cout << res.count() << "\n";
        }
    }
    return 0;
}