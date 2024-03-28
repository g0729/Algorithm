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

    ll n, k;
    cin >> n >> k;

    ll now = 0;

    for (int i = 1; i <= n; i++)
    {
        int length = to_string(i).length();
        for (int j = 0; j < length; j++)
        {
            now *= 10;
            now %= k;
        }
        now += i;
        now %= k;
    }
    cout << now;
    return 0;
}