#include <bits/stdc++.h>
using namespace std;
#define MAX 987654321

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b, c, m;

    cin >> a >> b >> c >> m;

    if (a > m)
    {
        cout << "0";
        return 0;
    }
    int sum = 0;
    int res = 0;
    for (int i = 0; i < 24; i++)
    {
        if (sum + a <= m)
        {
            sum += a;
            res += b;
        }
        else
        {
            sum=max(sum-c,0);
        }
    }

    cout<<res;
    return 0;
}
