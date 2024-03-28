#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

ll a, d, q;
ll gcd(ll a, ll b)
{
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}
ll cal(ll n)
{
    return n * (2 * a + (n - 1) * d) / 2;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> d >> q;
    ll GCD = gcd(a + d, a);
    while (q--)
    {
        ll b, l, r;
        cin >> b >> l >> r;
        if (b == 1)
            cout << cal(r) - cal(l - 1);
        else
        {
            if (l == r)
                cout << a + (l - 1) * d;
            else
                cout << GCD;
        }
        cout << "\n";
    }
    return 0;
}