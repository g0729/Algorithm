#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int a, b, n;
vector<pair<int, int>> l = {{0, -1}};
vector<pair<int, int>> r = {{0, -1}};

pair<int, int> bin_search(int num, int idx)
{
    int lo = -1, hi = n + 1;

    while (lo + 1 < hi)
    {
        int mid = (lo + hi) / 2;

        if ((b + num + r[mid].first) > a)
            hi = mid;
        else
            lo = mid;
    }

    if (hi == (n + 1))
        return {-2, -2};
    if ((b + num + r[hi].first) <= a)
        return {-2, -2};
    if (idx == -1 && r[hi].second == -1)
        return {-1, -1};

    if (r[hi].second == idx)
    {
        if (hi == n)
            return {-2, -2};
        hi++;
    }

    return {(b + num + r[hi].first - a), r[hi].second};
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> n;
    for (int i = 1; i <= n; i++)
    {
        int c, d;
        cin >> c >> d;
        l.push_back({c, i});
        r.push_back({d, i});
    }
    sort(r.begin(), r.end(), [](pair<int, int> &p1, pair<int, int> &p2) -> bool
         { return p1.first < p2.first; });

    int diff = 1e9;
    pair<int, int> res = {1e9, 1e9};
    for (int i = 0; i < n + 1; i++)
    {
        pair<int, int> temp = bin_search(l[i].first, l[i].second);
        if (temp.first == -2)
            continue;
        if (diff > temp.first)
        {
            diff = temp.first;
            res = {l[i].second, temp.second};
        }
    }
    if (res.first == 1e9)
        cout << "No";
    else
        cout << res.first << " " << res.second;

    return 0;
}