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

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int i = 0; i < 3; i++)
    {
        int e;
        cin >> e;
        e--;
        int res = 0;
        if (e % (a + b) < a)
            res++;
        if (e % (c + d) < c)
            res++;
        cout << res << "\n";
    }

    return 0;
}