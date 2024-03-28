#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a, b;
    int t, cnt1, cnt2;
    cnt1 = cnt2 = 0;
    cin >> t >> a >> b;

    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == b[i])
            cnt1++;
        else
            cnt2++;
    }
    int res;
    if (cnt1 >= t)
    {
        res = t + cnt2;
    }
    else
    {
        res=cnt1+cnt2-(t-cnt1);
    }

    cout<<res;
    return 0;
}