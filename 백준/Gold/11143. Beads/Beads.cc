#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
vector<ll> v;
vector<ll> tree;

int Sum(int start, int end, int node, int left, int right)
{
    if (right < start || left > end)
        return 0;
    if (left <= start && end <= right)
        return tree[node];

    int mid = (start + end) / 2;
    return Sum(start, mid, node * 2, left, right) + Sum(mid + 1, end, node * 2 + 1, left, right);
}
int update(int start, int end, int node, int idx, int val)
{
    if (idx < start || idx > end)
        return tree[node];
    if (start == end)
        return tree[node] += val;

    int mid = (start + end) / 2;
    return tree[node]=update(start, mid, node * 2, idx, val) + update(mid + 1, end, node * 2 + 1, idx, val);
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
        int b, p, q;
        cin >> b >> p >> q;

        v = vector<ll>(b + 1);
        tree = vector<ll>((b + 1) * 4);

        for (int i = 0; i < p + q; i++)
        {
            char com;
            int a, k;
            cin >> com >> a >> k;
            if (com == 'P')
                update(1, b, 1, a, k);
            else
                cout << Sum(1, b, 1, a, k) << "\n";
        }
    }
    return 0;
}