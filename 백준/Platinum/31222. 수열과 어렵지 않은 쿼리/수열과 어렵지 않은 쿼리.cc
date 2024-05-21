#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 200000
#define INF 987654321
int n, q;
vector<int> v;
vector<int> tree(4 * MAX);

int init(int start, int end, int node)
{
    if (start == end)
        return tree[node] = v[start] == v[start + 1] ? 0 : 1;

    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

int update(int start, int end, int node, int idx)
{
    if (idx < start || idx > end)
        return tree[node];
    if (start == end)
        return tree[node] = v[start] == v[start + 1] ? 0 : 1;
    int mid = (start + end) / 2;

    return tree[node] = update(start, mid, node * 2, idx) + update(mid + 1, end, node * 2 + 1, idx);
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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    if (n != 1)
        init(0, n - 2, 1);

    for (int i = 0; i < q; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (n == 1)
        {
            if (a == 2)
                cout << "1\n";
        }
        else
        {
            if (a == 1)
            {
                v[b - 1] = c;
                if (b == 1)
                    update(0, n - 2, 1, 0);
                else if (b == n)
                    update(0, n - 2, 1, n - 2);
                else
                {
                    update(0, n - 2, 1, b - 2);
                    update(0, n - 2, 1, b - 1);
                }
            }
            else
            {
                if (b == c)
                    cout << "1";
                else
                    cout << sum(0, n - 2, 1, b - 1, c - 2) + 1;
                cout << "\n";
            }
        }
    }

    return 0;
}