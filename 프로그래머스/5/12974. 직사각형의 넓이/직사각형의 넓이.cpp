#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define MAX 200000
vector<ll> tree(4 * MAX);
vector<ll> cnt(4 * MAX);
vector<ll> Y;
struct cord
{
    ll x, y1, y2;
    bool is_end;
    cord(ll x, ll y1, ll y2, bool is_end) : x(x), y1(y1), y2(y2), is_end(is_end){};
};

bool cmp(cord &a, cord &b)
{
    return a.x < b.x;
}
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
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}
ll solution(vector<vector<int>> rectangles)
{
    vector<cord> v;
    for (auto it : rectangles)
    {
        Y.push_back((ll)it[1] + 1);
        Y.push_back((ll)it[3] + 1);
        v.push_back(cord((ll)it[0], (ll)it[1] + 1, (ll)it[3] + 1, false));
        v.push_back(cord((ll)it[2], (ll)it[1] + 1, (ll)it[3] + 1, true));
    }
    sort(Y.begin(), Y.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());
    sort(v.begin(), v.end(), cmp);
    ll answer = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (i > 0)
        {
            ll diff = v[i].x - v[i - 1].x;
            answer += diff * tree[1];
        }
        ll val = v[i].is_end ? 1 : -1;
        ll left = lower_bound(Y.begin(), Y.end(), v[i].y1) - Y.begin();
        ll right = lower_bound(Y.begin(), Y.end(), v[i].y2) - Y.begin();
        update(1, MAX, 1, left + 1, right, val);
    }

    return answer;
}