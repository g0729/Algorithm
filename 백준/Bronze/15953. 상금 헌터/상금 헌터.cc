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

    int t;
    cin >> t;

    while (t--)
    {
        int a, b;
        cin >> a >> b;

        int res = 0;
        if (a == 1)
            res += 5000000;
        else if (a >= 2 && a <= 3)
            res += 3000000;
        else if (a >= 4 && a <= 6)
            res += 2000000;
        else if (a >= 7 && a <= 10)
            res += 500000;
        else if (a >= 11 && a <= 15)
            res += 300000;
        else if (a >= 16 && a <= 21)
            res += 100000;

        if (b == 1)
            res += 5120000;
        else if (b >= 2 && b <= 3)
            res += 2560000;
        else if (b >= 4 && b <= 7)
            res += 1280000;
        else if (b >= 8 && b <= 15)
            res += 640000;
        else if (b >= 16 && b <= 31)
            res += 320000;

        cout << res << "\n";
    }
    return 0;
}