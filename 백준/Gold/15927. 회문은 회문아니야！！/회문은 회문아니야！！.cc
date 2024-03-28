#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
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

    bool flag = true;

    for (int i = 0; i < s.length()/2; i++)
    {
        if (s[i] != s[s.length() - i - 1])
        {
            cout << s.length();
            return 0;
        }
        if (s[i] != s[i + 1])
            flag = false;
    }

    if (flag)
        cout << "-1";
    else
        cout << s.length() - 1;
    return 0;
}