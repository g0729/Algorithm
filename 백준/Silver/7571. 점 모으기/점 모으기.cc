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

    int n, m;
    cin >> n >> m;
    vector<int> x(m), y(m);

    for (int i = 0; i < m; i++)
    {
        cin >> x[i] >> y[i];
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int mx, my;
    mx = x[m / 2];
    my = y[m / 2];

    int res = 0;

    for (int i = 0; i < m; i++)
    {
        res += abs(x[i] - mx) + abs(y[i] - my);
    }

    cout << res;
    return 0;
}