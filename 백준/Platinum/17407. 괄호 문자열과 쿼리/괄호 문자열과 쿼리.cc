#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100010

vector<int> v;
vector<int> tree(4 * MAX);
vector<int> lazy(4 * MAX);

int init(int start, int end, int node)
{
    if (start == end)
    {
        return tree[node] = v[start];
    }
    int mid = (start + end) / 2;

    return tree[node] = min(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}
void update_lazy(int start, int end, int node)
{
    if (lazy[node] != 0)
    {
        tree[node] += lazy[node];
        if (start != end)
        {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}
int update(int start, int end, int node, int left, int right, int val)
{
    update_lazy(start, end, node);
    if (left > end || right < start)
        return tree[node];
    if (left <= start && end <= right)
    {
        if (start != end)
        {
            lazy[node * 2] += val;
            lazy[node * 2 + 1] += val;
        }
        return tree[node] += val;
    }

    int mid = (start + end) / 2;

    return tree[node] = min(update(start, mid, node * 2, left, right, val), update(mid + 1, end, node * 2 + 1, left, right, val));
}
int search(int start, int end, int node, int left, int right)
{
    update_lazy(start, end, node);

    if (left > end || right < start)
        return 1e9;
    if (left <= start && end <= right)
        return tree[node];

    int mid = (start + end) / 2;

    return min(search(start, mid, node * 2, left, right), search(mid + 1, end, node * 2 + 1, left, right));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    v = vector<int>(s.length() + 1);

    int n = s.length();
    for (int i = 1; i <= s.length(); i++)
    {
        v[i] = v[i - 1] + (s[i - 1] == '(' ? 1 : -1);
    }

    init(1, n, 1);

    int m;
    cin >> m;
    int res = 0;
    while (m--)
    {
        int a;
        cin >> a;
        int temp;
        if (s[a - 1] == '(')
        {
            s[a - 1] = ')';
            temp = -2;
        }
        else
        {
            s[a - 1] = '(';
            temp = 2;
        }
        update(1, n, 1, a, n, temp);
        if (search(1, n, 1, 1, n) == 0 && search(1, n, 1, n, n) == 0)
            res++;
    }

    cout << res;
    return 0;
}