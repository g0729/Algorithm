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
    ll a, b;
    cin >> a >> b;

    ll diff = b - a;
    if (diff == 0)
    {
        cout << "0";
        return 0;
    }
    ll n = 1;
    while (n * n <= diff)
        n++;
    n--;
    diff -= n * n;
    ll temp = (diff + n - 1) / n;
    ll res = 2 * n - 1 + temp;
    cout << res;
    return 0;
}