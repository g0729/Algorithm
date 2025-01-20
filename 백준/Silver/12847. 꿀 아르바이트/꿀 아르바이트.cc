#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
ll dx[] = {1, -1, 0, 0};
ll dy[] = {0, 0, 1, -1};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n);
    ll sum = 0;

    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += i < m ? v[i] : 0;
    }
    ll res = sum;
    for (ll i = m; i < n; i++)
    {
        sum += v[i] - v[i - m];
        res = max(res, sum);
    }

    cout << res;

    return 0;
}