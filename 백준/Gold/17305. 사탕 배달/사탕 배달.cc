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

    ll n, w;
    cin >> n >> w;
    vector<ll> v1, v2;

    for (ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        if (a == 3)
            v1.push_back(b);
        else if (a == 5)
            v2.push_back(b);
    }
    sort(v1.begin(), v1.end(), greater<ll>());
    sort(v2.begin(), v2.end(), greater<ll>());

    vector<ll> weight_sum_3(v1.size() + 1);
    vector<ll> weight_sum_5(v2.size() + 1);

    for (ll i = 1; i < v1.size() + 1; i++)
        weight_sum_3[i] = weight_sum_3[i - 1] + v1[i - 1];
    for (ll i = 1; i < v2.size() + 1; i++)
        weight_sum_5[i] = weight_sum_5[i - 1] + v2[i - 1];

    ll res = 0;
    for (ll i = 0; i <= min(w / 3, (ll)v1.size()); i++)
    {
        ll weight_5 = min((w - 3 * i) / 5, (ll)v2.size());

        ll sum = weight_sum_3[i] + weight_sum_5[weight_5];

        res = max(res, sum);
    }

    cout << res;
    return 0;
}