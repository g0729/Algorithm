#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
vector<int> tree(4 * MAX);

int init(int start, int end, int node)
{
    if (start == end)
        return tree[node] = 1;

    int mid = (start + end) / 2;

    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

int sum(int start, int end, int node, int left, int right)
{
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return tree[node];

    int mid = (start + end) / 2;

    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
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

    int n, p;
    cin >> n >> p;

    init(1, n, 1);

    int res = 0;
    while (p--)
    {
        int a;
        cin >> a;

        int temp = sum(1, n, 1, 1, a);
        if (temp == 0)
            break;
        res++;
        int idx = search(1, n, 1, temp);
        update(1, n, 1, idx);
    }

    cout << res;
    return 0;
}