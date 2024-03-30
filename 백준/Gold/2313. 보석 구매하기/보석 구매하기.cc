#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    ll res = 0;
    vector<pair<int, int>> res_idx;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n + 1);
        vector<int> dp(n + 1);
        pair<int, int> idx{1, 1};
        for (int i = 1; i <= n; i++)
            cin >> v[i];

        int max = v[1];
        pair<int, int> now_idx = {1, 1};
        for (int i = 1; i <= n; i++)
        {
            if (v[i] >= dp[i - 1] + v[i])
            {
                now_idx = {i, i};
                dp[i] = v[i];
            }
            else
            {
                now_idx.second = i;
                dp[i] = dp[i - 1] + v[i];
            }

            if (dp[i] > max)
            {
                max = dp[i];
                idx = now_idx;
            }
            else if (dp[i] == max)
            {
                if (now_idx.second - now_idx.first < idx.second - idx.first)
                    idx = now_idx;
            }
        }
        res += max;
        res_idx.push_back(idx);
    }

    cout << res << "\n";
    for (auto it : res_idx)
    {
        cout << it.first << " " << it.second << "\n";
    }
    return 0;
}