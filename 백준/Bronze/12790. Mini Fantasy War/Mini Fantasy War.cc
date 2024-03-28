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

    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d, e, f, g, h;
        cin >> a >> b >> c >> d >> e >> f >> g >> h;
        a += e;
        b += f;
        c += g;
        d += h;

        a = max(1, a);
        b = max(1, b);
        c = max(0, c);

        cout << a + 5 * b + 2 * c + 2 * d << "\n";
    }
    return 0;
}