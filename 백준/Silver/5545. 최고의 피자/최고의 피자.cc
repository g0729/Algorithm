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

    int n, a, b;
    cin >> n >> a >> b;
    vector<int> v(n);

    int sum;
    cin >> sum;
    int cost = a;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), greater<int>());

    int res = sum / cost;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        cost += b;
        res = max(res, sum / cost);
    }

    cout << res;

    return 0;
}