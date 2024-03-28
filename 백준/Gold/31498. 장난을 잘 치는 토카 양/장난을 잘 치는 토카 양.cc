#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
ll a, b, c, d, k;

bool check(ll target)
{
    ll sum = target * (2 * b + (target - 1) * (-k)) / 2;

    return sum >= a;
}
ll binsearch()
{
    ll lo = 0;
    ll hi = b / k + 1;
    while (lo + 1 < hi)
    {
        ll mid = (lo + hi) / 2;

        if (check(mid))
            hi = mid;
        else
            lo = mid;
    }
    return hi;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> c >> d >> k;

    ll time;
    if (k == 0)
        time = (a + b - 1) / b;
    else
    {
        time = binsearch();
        if (time == b / k + 1)
        {
            cout << "-1";
            return 0;
        }
    }

    if (time * d >= a + c)
        cout << "-1";
    else
        cout << time;
    return 0;
}