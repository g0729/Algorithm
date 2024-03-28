#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x;
    cin >> x;
    
    int now=64;
    int res = 0;

    while (now > 0)
    {
        if (x >= now)
        {
            x -= now;
            res++;
        }
        now/=2;
    }

    cout<<res;
    return 0;
}