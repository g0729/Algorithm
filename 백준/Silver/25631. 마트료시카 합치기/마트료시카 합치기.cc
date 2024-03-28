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

    sort(v.begin(), v.end());
    int res = 1;
    int temp = 1;
    for (int i = 1; i < n; i++)
    {
        if (v[i] == v[i - 1])
            temp++;
        else
            temp = 1;

        res = max(res, temp);
    }

    cout << res;
    return 0;
}