#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 200000
vector<ll> evenTree(MAX * 4);
vector<ll> oddTree(MAX * 4);

ll evenUpdate(int start, int end, int node, int idx, int val)
{
    if (idx < start || idx > end)
        return evenTree[node];
    if (start == end)
        return evenTree[node] += val;

    int mid = (start + end) / 2;

    return evenTree[node] = evenUpdate(start, mid, 2 * node, idx, val) + evenUpdate(mid + 1, end,node * 2 + 1, idx,val);
}
ll oddUpdate(int start, int end, int node, int idx, int val)
{
    if (idx < start || idx > end)
        return oddTree[node];
    if (start == end)
        return oddTree[node] += val;

    int mid = (start + end) / 2;

    return oddTree[node] = oddUpdate(start, mid, 2 * node, idx, val) + oddUpdate(mid + 1, end,node * 2 + 1, idx, val);
}
ll evenSum(int start, int end, int node, int left, int right)
{
    if (right < start || left > end)
        return 0;
    if (left <= start && end <= right)
        return evenTree[node];

    int mid = (start + end) / 2;

    return evenSum(start, mid, 2 * node, left, right) + evenSum(mid + 1, end, node * 2 + 1, left, right);
}
ll oddSum(int start, int end, int node, int left, int right)
{
    if (right < start || left > end)
        return 0;
    if (left <= start && end <= right)
        return oddTree[node];

    int mid = (start + end) / 2;

    return oddSum(start, mid, 2 * node, left, right) + oddSum(mid + 1, end, node * 2 + 1, left, right);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        if (i % 2 == 1)
            oddUpdate(1, (n + 1) / 2, 1, (i + 1) / 2, a);
        else
            evenUpdate(1, n / 2, 1, i / 2, a);
    }

    for (int i = 0; i < q; i++)
    {
        int op, a, b;
        cin >> op >> a >> b;

        if (op == 1)
        {
            ll LeftSum, RightSum;

            if (a % 2 == 1)
            {
                LeftSum = oddSum(1, (n + 1) / 2, 1, (a + 1) / 2, (b + 1) / 2);
                RightSum = evenSum(1, n / 2, 1, (a + 1) / 2, b / 2);
            }
            else
            {
                LeftSum = evenSum(1, n / 2, 1, a / 2, b / 2);
                RightSum = oddSum(1, (n + 1) / 2, 1, a / 2 + 1, (b + 1) / 2);
            }
            cout << std::abs(LeftSum - RightSum) << "\n";
        }
        else
        {
            if (a % 2 == 1)
                oddUpdate(1, (n + 1) / 2, 1, (a + 1) / 2, b);
            else
                evenUpdate(1, n / 2, 1, a / 2, b);
        }
    }

    return 0;
}