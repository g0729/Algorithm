#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
ll n, p, q;
map<ll, ll> ma;

ll cal(ll num)
{
    ll a, b;
    a = num / p;
    b = num / q;
    if (ma.find(a) != ma.end())
        a = ma[a];
    else
    {
        ma[a] = cal(a);
        a = ma[a];
    }
    if (ma.find(b) != ma.end())
        b = ma[b];
    else
    {
        ma[b] = cal(b);
        b = ma[b];
    }

    return a + b;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ma[0] = 1;

    cin >> n >> p >> q;
    if (n == 0)
        cout << "1";
    else
        cout << cal(n);
    return 0;
}