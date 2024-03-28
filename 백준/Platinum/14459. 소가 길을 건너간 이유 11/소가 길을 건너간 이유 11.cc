#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
int lef[MAX];
pair<int, int> rig[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<pair<int, int>> v;
    vector<int> dp;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> lef[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> rig[i].first;
        rig[i].second = i;
    }

    sort(rig + 1, rig + 1 + n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = max(1, lef[i] - 4); j <= min(n, lef[i] + 4); j++)
        {
            v.push_back({i, -rig[j].second});
        }
    }
    sort(v.begin(), v.end());
    dp.push_back(-v[0].second);
    for (int i = 1; i < v.size(); i++)
    {
        if (dp.back() < -v[i].second)
        {
            dp.push_back(-v[i].second);
            continue;
        }
        auto temp = lower_bound(dp.begin(), dp.end(), -v[i].second);
        *temp = -v[i].second;
    }
    cout << dp.size();
}
