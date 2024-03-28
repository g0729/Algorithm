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

    int n;

    cin >> n;
    vector<int> x(n);
    vector<int> y(n);

    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int mX = x[n / 2];
    int mY = y[n / 2];

    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        res += (ll)abs(x[i] - mX) + (ll)abs(y[i] - mY);
    }

    cout << res;

    return 0;
}