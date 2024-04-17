#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
vector<ll> v;
ll n, m, l;
bool f(pair<ll, ll> num)
{
    ll dis = l - num.second;
    int cnt = upper_bound(v.begin(), v.end(), num.first + dis) - lower_bound(v.begin(), v.end(), num.first - dis);

    return cnt > 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n >> l;
    for (int i = 0; i < m; i++)
    {
        ll a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;

        if (f({a, b}))
            res++;
    }

    cout << res;
    return 0;
}