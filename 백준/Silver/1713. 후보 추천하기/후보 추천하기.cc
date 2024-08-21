#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
#define pii pair<int, pair<int, int>>
bool min(pii &src, pii &target)
{
    if (src.second.first == target.second.first)
        return src.second.second < target.second.second;
    return src.second.first < target.second.first;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<pii> v;

    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        if (v.size() < n)
        {
            bool flag = true;
            for (int j = 0; j < v.size(); j++)
            {
                if (v[j].first == a)
                {
                    v[j].second.first++;
                    flag = false;
                    break;
                }
            }
            if (flag)
                v.push_back({a, {1, i}});
        }
        else
        {
            pii temp = v[0];
            int idx = 0;
            bool flag = true;
            for (int j = 0; j < n; j++)
            {
                if (v[j].first == a)
                {
                    v[j].second.first++;
                    flag = false;
                    break;
                }
                if (!min(temp, v[j]))
                {
                    temp = v[j];
                    idx = j;
                }
            }
            if (flag)
                v[idx] = {a, {1, i}};
        }
    }

    vector<int> res;

    for (int i = 0; i < v.size(); i++)
    {
        res.push_back(v[i].first);
    }

    sort(res.begin(), res.end());

    for (auto it : res)
        cout << it << " ";

    return 0;
}