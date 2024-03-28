#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    lint ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= i;

        while (ans % 10 == 0)
            ans /= 10;
        ans =ans% (lint)1e12;
    }
    ans=ans%(lint)1e5;
    cout.width(5);
    cout.fill('0');

    cout<<ans;
    return 0;
}