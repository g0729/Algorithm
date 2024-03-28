#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000

int n, k;
vector<int> v;
vector<int> sels;
int ans = 1e9;
void cal()
{
    int res = 0;
    if (sels[0] == 0)
        res += 1;
    else if (sels[0] % 2 == 1)
        res += sels[0] / 2 + 2;
    else
        res += sels[0] / 2 + 1;

    int temp = sels[1] - sels[0];

    res += (temp + 1) / 2;

    ans = min(ans, res);
}
void sel(int idx, int cnt)
{
    if (cnt == 2)
    {
        if (abs(v[sels[0]] - v[sels[1]]) >= k)
            cal();
        return;
    }

    for (int i = idx + 1; i < v.size(); i++)
    {
        sels.push_back(i);
        sel(i, cnt + 1);
        sels.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    int Min, Max;
    Min = 1e9;
    Max = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        Min = min(Min, a);
        Max = max(Max, a);
        v.push_back(a);
    }

    if (Max - Min < k)
    {
        cout << n;
        return 0;
    }
    sel(-1, 0);

    cout << ans;
    return 0;
}