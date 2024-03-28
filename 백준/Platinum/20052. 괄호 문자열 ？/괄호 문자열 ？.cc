#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100001

int sum[MAX];
vector<int> tree(4 * MAX);

int init(int start, int end, int node)
{
    if (start == end)
        return tree[node] = sum[start];

    int mid = (start + end) / 2;

    return tree[node] = min(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}
int Min(int start, int end, int node, int left, int right)
{
    if (right < start || left > end)
        return 1e9;
    if (left <= start && end <= right)
        return tree[node];

    int mid = (start + end) / 2;

    return min(Min(start, mid, node * 2, left, right), Min(mid + 1, end, node * 2 + 1, left, right));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    for (int i = 1; i <= s.length(); i++)
        sum[i] = sum[i - 1] + (s[i - 1] == '(' ? 1 : -1);

    init(1, s.length(), 1);

    int n;
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        if (sum[b] == sum[a - 1])
        {
            if (Min(1, s.length(), 1, a, b) >= sum[a - 1])
                res++;
            else
                continue;
        }
        else
            continue;
    }

    cout << res;
    return 0;
}