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
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        map<int, int> ma;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            ma[a]++;
        }

        ll res = 0;

        for (auto it : ma)
        {
            if (x == 0)
                res += (ll)it.second * (it.second - 1);
            else
                res += (ll)it.second * (ma[it.first ^ x]);
        }

        cout << res / 2 << "\n";
    }
    return 0;
}