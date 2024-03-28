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

    ll n, m;
    cin >> n >> m;
    ll res = 1;
    for (int i = 2; i <= n; i++)
    {
        res *= i;
        res %= m;
    }
    res %= m;
    cout << res;
    return 0;
}