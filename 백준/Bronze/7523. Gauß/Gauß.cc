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

    int t;
    cin >> t;

    for (int q = 1; q <= t; q++)
    {
        ll a, b;
        cin >> a >> b;

        cout << "Scenario #" << q << ":\n";
        cout << (a + b) * (b - a + 1) / 2 << "\n\n";
    }

    return 0;
}