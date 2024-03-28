#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

vector<int> tree(4 * MAX);

int init(int start, int end, int node)
{
    if (start == end)
        return tree[node] = 1;

    int mid = (start + end) / 2;

    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}
int update(int start, int end, int node, int idx)
{
    if (idx < start || idx > end)
        return tree[node];

    if (start == end)
        return tree[node] = 0;

    int mid = (start + end) / 2;

    return tree[node] = update(start, mid, node * 2, idx) + update(mid + 1, end, node * 2 + 1, idx);
}

int search(int start, int end, int node, int val)
{
    if (start == end)
        return start;

    int mid = (start + end) / 2;

    if (tree[node * 2] >= val)
        return search(start, mid, node * 2, val);
    else
        return search(mid + 1, end, node * 2 + 1, val - tree[node * 2]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> height(n+1);
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> height[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    sort(height.begin(), height.end());
    vector<int> res(n+1);
    init(1, n, 1);

    for (int i = n; i > 0; i--)
    {
        int now = v[i]+1;

        int temp = search(1, n, 1, now);

        update(1, n, 1, temp);

        res[i] = height[temp];
    }

    for (int i = 1; i <= n; i++)
        cout << res[i] << "\n";

    return 0;
}