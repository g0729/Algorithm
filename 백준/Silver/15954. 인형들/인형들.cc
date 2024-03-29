#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

int n, k;
vector<int> v;

double get_std(int start, int nums)
{
    double mean = 0;

    for (int i = 0; i < nums; i++)
        mean += v[start + i];
    mean /= nums;

    double vsum = 0;

    for (int i = 0; i < nums; i++)
    {
        double temp = (v[start + i] - mean);
        vsum += temp * temp;
    }
    vsum /= nums;

    return sqrt(vsum);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    double res = 1e9;

    for (int i = k; i <= n; i++)
    {
        for (int j = 0; j + i <= n; j++)
            res = min(res, get_std(j, i));
    }

    cout << fixed;
    cout.precision(12);
    cout << res;

    return 0;
}