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

    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ll res = 0;
    ll now = 0;
    for (ll i = n - 1; i >= 0; i--)
    {
        if (v[i] > now)
            now++;
        else
            now = v[i];
        res += now;
    }

    cout << res;
    return 0;
}