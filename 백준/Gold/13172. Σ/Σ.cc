#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000

ll myPow(ll base, ll exp)
{
    if (exp == 1)
        return base;

    ll temp = myPow(base, exp / 2);

    ll ans = (temp * temp) % MOD;

    if (exp % 2)
        ans = (ans * base) % MOD;

    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    ll res = 0;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        ll temp = myPow(a, MOD - 2);
        temp = (b * temp) % MOD;

        res = (res + temp) % MOD;
    }

    cout << res;
    return 0;
}