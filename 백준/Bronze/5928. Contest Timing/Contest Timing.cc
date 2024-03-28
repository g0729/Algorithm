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

    int a, b, c;
    cin >> a >> b >> c;

    int res = 1440 * 11 + 60 * 11 + 11;
    res = 1440 * a + b * 60 + c - res;
    if (res < 0)
        cout << "-1";
    else
        cout << res;
    return 0;
}