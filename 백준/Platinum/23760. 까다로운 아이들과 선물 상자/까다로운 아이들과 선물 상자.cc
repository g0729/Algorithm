#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000
vector<int> tree(4 * (MAX + 1));
vector<int> want(MAX + 1);
vector<int> v(MAX + 1);
int n, m;

int update(int start, int end, int node, int idx, int val)
{
    if (idx < start || idx > end)
        return tree[node];

    if (start == end)
        return tree[node] += val;

    int mid = (start + end) / 2;

    return tree[node] = update(start, mid, node * 2, idx, val) + update(mid + 1, end, node * 2 + 1, idx, val);
}

int search(int start, int end, int node, int val)
{
    if (start == end)
        return start;

    int mid = (start + end) / 2;

    if (tree[node * 2 + 1] >= val)
        return search(mid + 1, end, node * 2 + 1, val);
    else
        return search(start, mid, node * 2, val - tree[node * 2 + 1]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        update(0, MAX, 1, a, 1);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> want[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < m; i++)
    {
        int temp = search(0, MAX, 1, v[i]);
        if (want[i] > temp)
        {
            cout << "0";
            return 0;
        }
        update(0, MAX, 1, temp - want[i], 1);
        update(0, MAX, 1, temp, -1);
    }
    cout << "1";
    return 0;
}