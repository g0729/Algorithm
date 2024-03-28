#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
#define MOD 1000000007

vector<int> tree;

int init(int start, int end, int node)
{
    if (start == end)
        return tree[node] = 1;

    int mid = (start + end) / 2;

    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}
int Search(int start, int end, int node, int val)
{
    if (start == end)
        return start;

    int mid = (start + end) / 2;

    if (tree[node * 2] >= val)
        return Search(start, mid, node * 2, val);
    else
        return Search(mid + 1, end, node * 2 + 1, val - tree[node * 2]);
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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    tree = vector<int>(4 * (n + 1));

    init(1, n, 1);

    cout << "<";
     int now = 1;
    for (int i = 0; i < n; i++)
    {
        now += k - 1;

        if (now % tree[1] == 0)
            now = tree[1];
        else if (now > tree[1])
            now %= tree[1];

        int temp = Search(1, n, 1, now);
        update(1, n, 1, temp);
        if (i == n - 1)
            cout << temp << ">";
        else
            cout << temp << ", ";
    }

    return 0;
}