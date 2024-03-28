#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] <= 'z' && s[i] >= 'a')
            s[i] = s[i] - 'a' + 'A';
        else
            s[i] = s[i] - 'A' + 'a';
    }
    cout<<s;
}