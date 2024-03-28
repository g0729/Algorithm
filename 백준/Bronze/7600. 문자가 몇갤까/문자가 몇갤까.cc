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
    while (1)
    {
        getline(cin, s);

        if (s == "#")
            break;

        bool alpha[26] = {0};

        for (int i = 0; i < s.length(); i++)
        {
            if (isalpha(s[i]))
            {
                alpha[tolower(s[i]) - 'a'] = true;
            }
        }

        int res = 0;

        for (int i = 0; i < 26; i++)
        {
            if (alpha[i])
                res++;
        }

        cout << res << "\n";
    }
    return 0;
}