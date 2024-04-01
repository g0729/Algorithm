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

    ll a, b, c, d, u;
    cin >> a >> b >> c >> d >> u;

    ll res = 0;

    if (d == 1 && c <= u)
    {
        if (a <= c && (c - a) % b == 0)
        {
        }
        else
            res++;
    }
    else
    {
        ll now = c;
        while (now <= u)
        {
            res++;
            if (now - a >= 0 && (now - a) % b == 0)
                res--;
            now *= d;
        }
    }
    if (u >= a)
        res += (u - a) / b + 1;
    cout << res;
    return 0;
}