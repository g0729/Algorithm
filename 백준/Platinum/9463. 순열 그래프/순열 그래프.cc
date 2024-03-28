#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000
vector<int> tree;

int sum(int start, int end, int node, int left, int right)
{
    if (right < left || left > end)
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
        return tree[node] = 1;

    int mid = (start + end) / 2;

    return tree[node] = update(start, mid, node * 2, idx) + update(mid + 1, end, node * 2 + 1, idx);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        tree = vector<int>(4 * (n + 1));

        vector<int> arrA(n + 1);
        vector<int> arrB(n + 1);

        for (int i = 1; i <= n; i++)
            cin >> arrA[i];

        for (int i = 1; i <= n; i++)
        {
            int a;
            cin >> a;
            arrB[a] = i;
        }

        ll res = 0;
        for (int i = 1; i <= n; i++)
        {
            res = res + (ll)sum(1, n, 1, arrB[arrA[i]] + 1, n);
            update(1, n, 1, arrB[arrA[i]]);
        }
        cout<<res<<"\n";
    }
    return 0;
}