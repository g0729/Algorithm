#include <bits/stdc++.h>
using namespace std;

char vowel[5] = {'a', 'e', 'i', 'o', 'u'};

int main()
{
    while (1)
    {
        string s;
        cin >> s;
        if (s == "end")
            return 0;

        bool check_first = false;
        int cnt = 1;
        bool check_second = true;
        bool now = true;
        bool check_third = true;
        for (int i = 0; i < 5; i++)
        {
            if (s[0] == vowel[i])
            {
                now = false;
                check_first = true;
            }
        }

        for (int i = 1; i < s.length(); i++)
        {
            bool temp = true;
            for (int j = 0; j < 5; j++)
            {
                if (s[i] == vowel[j])
                {
                    check_first = true;
                    temp = false;
                }
            }
            if (temp == now)
                cnt++;
            else
                cnt = 1;
            if (cnt == 3)
            {
                check_second = false;
                break;
            }
            if (s[i] == s[i - 1])
            {
                if (s[i] == 'e' || s[i] == 'o')
                    continue;
                else
                {
                    check_third = false;
                    break;
                }
            }
            now = temp;
        }
        if (check_first && check_second && check_third)
            cout << "<" << s << "> is acceptable.\n";
        else
            cout << "<" << s << "> is not acceptable.\n";
    }
}