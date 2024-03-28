#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000
vector<ll> Sumtree((MAX + 1) * 4);
vector<ll> Mllree((MAX + 1) * 4);
vector<ll> v(MAX + 1);
pair<ll, ll> resLR;
ll res = -1;
ll n;
ll Suminit(ll start, ll end, ll node)
{
    if (start == end)
        return Sumtree[node] = v[start];
    ll mid = (start + end) / 2;

    return Sumtree[node] = Suminit(start, mid, node * 2) + Suminit(mid + 1, end, node * 2 + 1);
}
ll Mininit(ll start, ll end, ll node)
{
    if (start == end)
        return Mllree[node] = start;

    ll mid = (start + end) / 2;

    ll LeftIdx = Mininit(start, mid, node * 2);
    ll RightIdx = Mininit(mid + 1, end, node * 2 + 1);

    if (v[LeftIdx] < v[RightIdx])
        return Mllree[node] = LeftIdx;
    else
        return Mllree[node] = RightIdx;
}
ll Sum(ll start, ll end, ll node, ll left, ll right)
{
    if (right < start || end < left)
        return 0;
    if (left <= start && end <= right)
        return Sumtree[node];

    ll mid = (start + end) / 2;

    return Sum(start, mid, node * 2, left, right) + Sum(mid + 1, end, node * 2 + 1, left, right);
}
ll Min(ll start, ll end, ll node, ll left, ll right)
{

    if (right < start || end < left)
        return 1e9;
    if (left <= start && end <= right)
        return Mllree[node];

    ll mid = (start + end) / 2;

    ll LeftIdx = Min(start, mid, node * 2, left, right);
    ll RightIdx = Min(mid + 1, end, node * 2 + 1, left, right);

    if (LeftIdx == 1e9)
        return RightIdx;
    else if (RightIdx == 1e9)
        return LeftIdx;
    if (v[LeftIdx] < v[RightIdx])
        return LeftIdx;
    else
        return RightIdx;

    return min(Min(start, mid, node * 2, left, right), Min(mid + 1, end, node * 2 + 1, left, right));
}
void Divide(ll l, ll r)
{
    if (l > r)
        return;

    ll temp = Min(1, n, 1, l, r);
    ll temp2 = v[temp] * Sum(1, n, 1, l, r);

    if (temp2 > res)
    {
        res = temp2;
        resLR = {l, r};
    }
    Divide(l, temp - 1);
    Divide(temp + 1, r);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> v[i];
    Suminit(1, n, 1);
    Mininit(1, n, 1);
    Divide(1, n);
    cout << res << "\n"
         << resLR.first << " " << resLR.second;
    return 0;
}