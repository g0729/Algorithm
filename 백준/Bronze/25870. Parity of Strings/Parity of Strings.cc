#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cnt[26] = {};

    string s;

    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        cnt[s[i] - 'a']++;
    }

    int cnt_odd = 0;
    int cnt_even = 0;

    for (int i = 0; i < 26; i++)
    {
        if(cnt[i]==0)
        continue;
        if (cnt[i] % 2 == 0)
            cnt_even++;
        else
            cnt_odd++;
    }

    if (cnt_even == 0 && cnt_odd != 0)
    {
        cout << "1";
    }
    else if (cnt_even != 0 && cnt_odd == 0)
    {
        cout << "0";
    }
    else
        cout << "2";
}