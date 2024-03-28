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

    int n, m, k;
    map<string, int> ma;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        ma[s]++;
    }
    cin >> k;

    int res = 0;
    for (auto it : ma)
    {
        int cnt = 0;
        for (int i = 0; i < it.first.length(); i++)
        {
            if (it.first[i] == '0')
                cnt++;
        }
        if (cnt <= k && (k - cnt) % 2 == 0)
            res = max(res, it.second);
    }

    cout << res;
    return 0;
}