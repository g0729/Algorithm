#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;

    getline(cin, s);

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            int temp = s[i] + 13;
            if (temp > 'z')
                temp -= 26;
            s[i] = temp;
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            int temp = s[i] + 13;
            if (temp > 'Z')
                temp -= 26;
            s[i] = temp;
        }
    }

    cout << s;
}