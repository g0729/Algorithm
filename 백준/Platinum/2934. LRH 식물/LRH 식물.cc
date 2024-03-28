#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000

vector<int> tree(4 * MAX);

void update(int start, int end, int node, int left, int right, int val)
{
    if (left > end || right < start)
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
ll search(int start, int end, int node, int idx, ll res)
{
    if (idx < start || idx > end)
        return 0;
    res += tree[node];

    if (start == end)
        return res;

    int mid = (start + end) / 2;

    return search(start, mid, node * 2, idx, res) + search(mid + 1, end, node * 2 + 1, idx, res);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        int res = 0;
        int temp;
        temp = search(0, MAX, 1, a, 0LL);
        if (temp)
            update(0, MAX, 1, a, a, -temp);
        res += temp;
        temp = search(0, MAX, 1, b, 0LL);
        if (temp)
            update(0, MAX, 1, b, b, -temp);
        res += temp;
        update(0, MAX, 1, a + 1, b - 1, 1);
        cout << res << "\n";
    }

    return 0;
}