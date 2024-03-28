#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    int left, right;

    left = 1;
    right = m;
    int p;
    cin >> p;
    int res = 0;
    while (p--)
    {
        int a;
        cin >> a;

        if (left <= a && a <= right)
            continue;
        else if (a > right)
        {
            res += a - right;
            right = a;
            left = a - m + 1;
        }
        else
        {
            res += left - a;
            left = a;
            right = a + m - 1;
        }
    }

    cout << res;
    return 0;
}