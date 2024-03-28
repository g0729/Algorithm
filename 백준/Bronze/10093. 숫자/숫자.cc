#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll a, b, c, d;
    cin >> c >> d;
    a = min(c, d);
    b = max(c, d);
    if (a == b)
    {
        cout << "0";
        return 0;
    }
    cout << (b - a - 1) << "\n";

    for (ll i = a + 1; i < b; i++)
    {
        cout << i << " ";
    }

    return 0;
}