#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD (ll)1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

ll pow(ll base, ll exp)
{
    if (exp == 0)
        return 1;

    ll temp = pow(base, exp / 2);
    temp = (temp * temp) % MOD;
    if (exp % 2)
        return (temp * base) % MOD;
    else
        return temp;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll a, b;
    cin >> a >> b;

    if (a == 1)
    {
        cout << b % MOD;
        return 0;
    }
    ll res = pow(a, b) - 1;
    ll temp = pow(a - 1, MOD - 2);
    res = (res * temp) % MOD;

    cout << res;
    return 0;
}