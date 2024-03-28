#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    vector<int> dp;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    dp.push_back(v[0]);

    for (int i = 1; i < v.size(); i++)
    {
        if (dp.back() < v[i])
        {
            dp.push_back(v[i]);
            continue;
        }
        auto temp = lower_bound(dp.begin(), dp.end(), v[i]);
        *temp = v[i];
    }
    cout << n - dp.size();
}