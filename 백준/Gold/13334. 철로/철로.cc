#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second != b.second)
        return a.second < b.second;
    else
        return a.first < b.first;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
        if (v[i].first > v[i].second)
            swap(v[i].first, v[i].second);
    }
    int d;
    cin >> d;

    sort(v.begin(), v.end(), cmp);

    int res = 0;

    for (int i = 0; i < n; i++)
    {
        if (v[i].second - v[i].first <= d)
            pq.push(v[i].first);
        else
            continue;

        while (!pq.empty())
        {
            if (v[i].second - pq.top() <= d)
                break;
            else
                pq.pop();
        }
        res = max(res, (int)pq.size());
    }

    cout << res;

    return 0;
}