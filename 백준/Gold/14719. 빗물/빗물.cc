#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000

vector<int> tree(5000);
vector<int> v(1000);
int init(int start, int end, int node)
{
    if (start == end)
        return tree[node] = v[start];

    int mid = (start + end) / 2;

    return tree[node] = max(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

int max(int start, int end, int node, int left, int right)
{
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return tree[node];

    int mid = (start + end) / 2;

    return max(max(start, mid, node * 2, left, right), max(mid + 1, end, node * 2 + 1, left, right));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, h;
    cin >> h >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    init(0, n - 1, 1);

    int res = 0;
    for (int i = 1; i < n - 1; i++)
    {
        res += max(0, min(max(0, n - 1, 1, 0, i - 1), max(0, n - 1, 1, i + 1, n - 1)) - v[i]);
    }

    cout << res;
    return 0;
}