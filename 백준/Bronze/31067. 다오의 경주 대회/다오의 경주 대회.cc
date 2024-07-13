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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int res = 0;
    for (int i = 1; i < n; i++)
    {
        if (v[i] + k <= v[i - 1])
        {
            cout << "-1";
            return 0;
        }
        if (v[i] > v[i - 1])
            continue;
        v[i] += k;
        res++;
    }

    cout << res;
    return 0;
}