#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
ll n;

ll f()
{
    ll res = n;
    ll sqrtn = sqrt(n);

    for (ll div = 2; div <= sqrtn; div++)
    {
        if (n % div == 0)
            res = res / div * (div - 1);
        while (n % div == 0)
        {
            n /= div;
        }
    }

    if (n != 1)
        res = res / n * (n - 1);
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    ll res = f();

    cout << res;
    return 0;
}