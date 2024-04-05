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

    int res = 0;
    int n;
    cin >> n;
    for (int i = 0; i < 2 * n; i++)
    {
        int a;
        cin >> a;
        res += abs(a);
    }

    cout << res;
    return 0;
}