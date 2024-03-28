#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    int res=0;
    for (int i = 1;; i++)
    {
        if (n >= 2 * i && m >= i && (n - 2 * i + m - i) >= k)
            res = i;
        else
            break;
    }
    cout << res;
    return 0;
}