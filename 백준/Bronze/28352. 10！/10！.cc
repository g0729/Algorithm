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

    int n;
    cin >> n;

    int res = 6;
    for (int i = 11; i <= n; i++)
    {
        res *= i;
    }

    cout << res;
    return 0;
}