#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 450000

vector<ll> cnt(4 * MAX);
vector<ll> tree(4 * MAX);
vector<ll> Y;
struct cordi
{
    ll x, y1, y2;
    bool isEnd;
    cordi(ll x, ll y1, ll y2, bool isEnd) : x(x), y1(y1), y2(y2), isEnd(isEnd){};
};
void update(ll start, ll end, ll node, ll left, ll right, ll val)
{
    if (left > end || right < start)
        return;
    if (left <= start && end <= right)
        cnt[node] += val;
    else
    {
        ll mid = (start + end) / 2;
        update(start, mid, node * 2, left, right, val);
        update(mid + 1, end, node * 2 + 1, left, right, val);
    }
    if (cnt[node])
        tree[node] = (Y[end] - Y[start - 1]);
    else
    {
        if (start == end)
            tree[node] = 0;
        else
        {
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }
}
bool cmp(cordi &a, cordi &b)
{
    return a.x < b.x;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;

    vector<cordi> v;
    for (ll i = 0; i < n; i++)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        Y.push_back(c + 1);
        Y.push_back(d + 1);
        v.push_back(cordi(a, c + 1, d + 1, false));
        v.push_back(cordi(b, c + 1, d + 1, true));
    }

    sort(Y.begin(), Y.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());
    sort(v.begin(), v.end(), cmp);

    ll res = 0;
    for (ll i = 0; i < v.size(); i++)
    {
        if (i > 0)
        {
            ll diff = v[i].x - v[i - 1].x;
            res += diff * tree[1];
        }
        ll val = v[i].isEnd ? 1 : -1;
        ll left = lower_bound(Y.begin(), Y.end(), v[i].y1) - Y.begin();
        ll right = lower_bound(Y.begin(), Y.end(), v[i].y2) - Y.begin();
        update(1, MAX, 1, left + 1, right, val);
    }

    cout << res;
    return 0;
}