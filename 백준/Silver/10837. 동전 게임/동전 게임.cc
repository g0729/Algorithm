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
    int k, n;
    cin >> k >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        int round = k - max(a, b);
        bool res = false;
        if (a == b)
            res = true;
        else if (a > b)
        {
            if (a - b <= round + 2)
                res = true;
            else
                res = false;
        }
        else
        {
            if (b - a <= round + 1)
                res = true;
            else
                res = false;
        }
        if (res)
            cout << "1";
        else
            cout << "0";
        cout << "\n";
    }
    return 0;
}