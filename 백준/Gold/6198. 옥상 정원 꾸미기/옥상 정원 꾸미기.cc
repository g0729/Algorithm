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

    ll n;
    cin >> n;
    vector<ll> v(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    stack<pair<ll, ll>> st;
    ll res = 0;
    st.push({v[0], 0});

    for (ll i = 1; i < n; i++)
    {
        if (st.top().first > v[i])
            st.push({v[i], i});
        else
        {
            while (!st.empty() && st.top().first <= v[i])
            {
                res += (i - st.top().second - 1);
                st.pop();
            }
            st.push({v[i], i});
        }
    }
    st.pop();
    while (!st.empty())
    {
        res += (n - st.top().second - 1);
        st.pop();
    }
    cout << res;
    return 0;
}