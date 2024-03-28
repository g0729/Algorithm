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
    ll n, k;
    cin >> n >> k;
    ll first;
    cin >> first;

    ll sum = 0;
    ll MIN = 1e9;
    for (ll i = 0; i < n - 1; i++)
    {
        ll a;
        cin >> a;
        ll temp = first + (i + 1) * k - a;

        sum += temp;
        MIN = min(temp, MIN);
    }

    if (MIN < 0)
        sum += (-MIN) * n;

    cout << sum;
    return 0;
}