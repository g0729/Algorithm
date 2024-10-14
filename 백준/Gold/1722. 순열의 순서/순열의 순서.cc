#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
ll dx[] = {1, -1, 0, 0};
ll dy[] = {0, 0, 1, -1};

vector<ll> fac;
int n;
ll cal_index(ll now, ll sum, vector<ll> &v, vector<bool> &is_used)
{

    if (now == n)
        return sum;
    int idx = 0;
    for (int i = 1; i < v[now]; i++)
    {
        if (is_used[i])
            continue;
        idx++;
    }
    is_used[v[now]] = true;

    ll next_sum = sum + fac[n - now - 1] * idx;

    return cal_index(now + 1, next_sum, v, is_used);
}

void cal_permu(ll now, ll left, vector<ll> &res, vector<bool> &is_used)
{
    if (now == n)
        return;
    ll idx = left / fac[n - now - 1];
    ll val = 0;

    for (int i = 1; i <= n; i++)
    {
        if (is_used[i])
            continue;
        if (idx == 0)
        {
            val = i;
            break;
        }
        idx--;
    }

    is_used[val] = true;
    res.push_back(val);
    cal_permu(now + 1, left % fac[n - now - 1], res, is_used);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<bool> is_used(n + 1);
    fac.push_back(1);
    fac.push_back(1);
    for (int i = 2; i <= 20; i++)
        fac.push_back(fac[i - 1] * i);

    int k;
    cin >> k;

    if (k == 1)
    {
        ll idx;
        cin >> idx;

        vector<ll> res;

        cal_permu((ll)0, idx - 1, res, is_used);

        for (auto it : res)
            cout << it << " ";
    }
    else
    {
        vector<ll> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        cout << cal_index((ll)0, (ll)0, v, is_used) + 1;
    }
    return 0;
}