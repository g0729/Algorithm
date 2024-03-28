#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m;

    cin >> n >> m;

    ll res = 1;

    for (int i = 0; i < n; i++)
    {
        res = (res * m) % MOD;
    }

    ll temp = 1;

    for (int i = 0; i < n; i++)
    {
        temp = (temp * (m - 1)) % MOD;
    }

    res = (res - temp) % MOD;

    if (res < 0)
        res += MOD;

    cout << res;
    return 0;
}