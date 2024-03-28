#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    vector<ll> v(n + 1);
    vector<ll> sum(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        sum[i] = sum[i - 1] + v[i];
    }

    int start = 1;

    while (q--)
    {
        int a, b, c;
        cin >> a >> b;
        if (a == 1)
            start = (n - b + start - 1) % n + 1;
        else if (a == 2)
            start = (start + b - 1) % n + 1;
        else
        {
            cin >> c;
            int left, right;
            left = (start + (b - 2)) % n + 1;
            right = (start + (c - 2)) % n + 1;
            ll res;
            if (left <= right)
                res = sum[right] - sum[left - 1];
            else
                res = sum[n] - (sum[left - 1] - sum[right]);
            cout << res << "\n";
        }
    }
    return 0;
}