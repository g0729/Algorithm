#include <bits/stdc++.h>
using namespace std;
#define INF 9876543210
#define lint long long

vector<pair<lint, lint>> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        pair<lint, lint> a;
        cin >> a.first >> a.second;

        v.push_back(a);
    }

    sort(v.begin(), v.end());

    lint start, end, res;

    res = 0;
    start = end = -INF;

    for (int i = 0; i < n; i++)
    {
        if (end >= v[i].first)
        {
            end = max(end, v[i].second);
        }
        else
        {
            res += end - start;
            start = v[i].first;
            end = v[i].second;
        }
    }

    res += end - start;

    cout << res;
    return 0;
}