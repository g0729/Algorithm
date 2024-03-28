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

    cout << fixed;
    cout.precision(2);
    int t;
    cin >> t;
    while (t--)
    {
        double a;
        cin >> a;

        string s;
        getline(cin, s);

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '@')
                a *= 3;
            if (s[i] == '%')
                a += 5;
            if (s[i] == '#')
                a -= 7;
        }

        cout << a << "\n";
    }
    return 0;
}