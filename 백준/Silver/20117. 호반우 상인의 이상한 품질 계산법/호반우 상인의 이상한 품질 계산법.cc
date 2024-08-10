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

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int res = 0;

    sort(v.begin(), v.end());

    for (int i = 0; i < n / 2; i++)
        res += v[n - i - 1] * 2;
    if (n % 2)
        res += v[n / 2];
    cout << res;
    return 0;
}