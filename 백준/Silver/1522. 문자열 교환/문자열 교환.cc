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

    string s;
    cin >> s;

    int wSize = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'a')
            wSize++;
    }

    int a_cnt, b_cnt;
    a_cnt = b_cnt = 0;
    for (int i = 0; i < wSize; i++)
    {
        if (s[i] == 'a')
            a_cnt++;
        else
            b_cnt++;
    }
    int res = b_cnt;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'a')
            a_cnt--;
        else
            b_cnt--;

        if (s[(i + wSize) % s.length()] == 'a')
            a_cnt++;
        else
            b_cnt++;

        res = min(res, b_cnt);
    }

    cout << res;

    return 0;
}