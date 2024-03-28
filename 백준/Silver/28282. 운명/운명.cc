#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, k;
    cin >> n >> k;

    vector<ll> left(k + 1);
    vector<ll> right(k + 1);

    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        left[a]++;
    }

    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        right[a]++;
    }

    ll res = 0;
    for (ll i = 1; i <= k; i++)
    {
        res += left[i] * (n - right[i]);
    }

    cout << res;
    return 0;
}