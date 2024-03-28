#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

string f(string &s)
{
    string temp;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
            continue;

        if (s[i] == '0' && temp.empty())
            continue;
        temp.push_back(s[i]);
    }

    return temp;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;

    cin >> s;

    int res = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
            res++;
    }

    s = f(s);

    while (1)
    {
        if (s.empty())
            break;

        if (s.back() == '0')
            res += 9;
        else
            res += s.back() - '1' + 1;
        s.back() = '1';
        s = f(s);
    }

    cout << res;
    return 0;
}