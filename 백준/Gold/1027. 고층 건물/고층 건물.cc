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
    ll n;

    cin >> n;
    vector<ll> v(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ll res = 0;
    for (ll i = 0; i < n; i++)
    {
        ll cnt = 0;
        for (ll j = 0; j < i; j++)
        {
            bool flag = false;
            double slope = (double)(v[i] - v[j]) / (double)(i - j);
            for (ll k = j + 1; k < i; k++)
            {
                ll diff = k - j;
                double height = v[j] + slope * diff;
                if (height <= v[k])
                {
                    flag = true;
                    break;
                }
            }
            if (!flag)
                cnt++;
        }
        for (ll j = i + 1; j < n; j++)
        {
            bool flag = false;
            double slope = (double)(v[j] - v[i]) / (double)(j - i);
            for (ll k = j - 1; k > i; k--)
            {
                ll diff = k - j;
                double height = v[j] + slope * diff;
                if (height <= v[k])
                {
                    flag = true;
                    break;
                }
            }
            if (!flag)
                cnt++;
        }
        res = max(cnt, res);
    }

    cout << res;
    return 0;
}