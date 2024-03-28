#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    int res;

    int now;
    if (s[0] == 'c')
        now = 26;
    else
        now = 10;

    res = now;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == s[i - 1])
        {
            if (s[i] == 'c')
                now = 25;
            else
                now = 9;
        }
        else
        {
            if (s[i] == 'c')
                now = 26;
            else
                now = 10;
        }
        res *= now;
    }

    cout << res;
    return 0;
}