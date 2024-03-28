#include <bits/stdc++.h>
using namespace std;
#define lint long long
vector<pair<int, int>> v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    lint left = 0;
    lint right = 0;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        right += b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());
    lint diff = 1e15;
    lint res_i;
    for (int i = 0; i < n; i++)
    {
        left += v[i].second;
        lint temp = abs(right - left);
        if (temp < diff)
        {
            res_i = v[i].first;
            diff = temp;
        }
        right -= v[i].second;
    }
    cout << res_i;
}