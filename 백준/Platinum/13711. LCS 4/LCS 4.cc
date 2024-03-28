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

    int n;
    cin >> n;
    vector<int> v(n + 1);
    vector<int> v2(n);

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v[a] = i;
    }
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v2[i] = v[a];
    }

    vector<int> dp;
    dp.push_back(v2[0]);
    for (int i = 1; i < n; i++)
    {
        if (dp.back() < v2[i])
            dp.push_back(v2[i]);
        else
        {
            auto temp = lower_bound(dp.begin(), dp.end(), v2[i]);
            *temp = v2[i];
        }
    }

    cout << dp.size();
    return 0;
}