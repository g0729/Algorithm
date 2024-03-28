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
    string s;

    cin >> n >> s;

    int start, end;
    start = end = 0;
    int cnt = 0;
    int alpha[26] = {
        0,
    };
    int res = 0;
    while (end < s.length())
    {

        if (cnt <= n)
        {
            alpha[s[end] - 'a']++;

            if (alpha[s[end] - 'a'] == 1)
                cnt++;
            end++;
            if (cnt <= n)
                res = max(res, end - start);
        }
        else
        {
            alpha[s[start] - 'a']--;

            if (alpha[s[start] - 'a'] == 0)
                cnt--;
            start++;
        }
    }

    cout << res;
    return 0;
}