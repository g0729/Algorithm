#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

ll n, m;
vector<ll> v;

bool check(ll target)
{
    ll sum = 0;

    for (auto it : v)
    {
        sum += it / target;
    }

    return sum >= m;
}
ll f()
{
    ll start, end;
    start = 0;
    end = 1e10;

    while (start + 1 < end)
    {
        ll mid = (start + end) / 2;

        if (check(mid))
            start = mid;
        else
            end = mid;
    }

    return start;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        v.push_back(a);
    }

    ll ans = 0;
    ll div = f();

    for (auto it : v)
        ans += it;

    ans = ans - div * m;
    cout << ans;
    return 0;
}