#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a = "UCPC";
    string s;

    getline(cin, s);

    int now = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == a[now])
        {
            now++;
            if (now == 4)
            {
                cout << "I love UCPC";
                return 0;
            }
        }
    }

    cout << "I hate UCPC";

    return 0;
}