#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

double distance(pair<double, double> &a, pair<double, double> &b)
{
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    double d;
    int n;
    while (1)
    {
        cin >> d >> n;
        if (d == 0 && n == 0)
            break;

        vector<pair<double, double>> v(n);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i].first >> v[i].second;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;

                if (distance(v[i], v[j]) <= d)
                {
                    cnt++;
                    break;
                }
            }
        }

        cout << cnt << " sour, " << n - cnt << " sweet\n";
    }
    return 0;
}