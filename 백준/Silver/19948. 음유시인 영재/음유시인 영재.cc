#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

char to_lower(char &c)
{
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 'a';
    else
        return c;
}
char to_upper(char &c)
{
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 'A';
    else
        return c;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    getline(cin, s);

    int n;
    cin >> n;
    vector<int> alpha(26);
    string res;
    for (int i = 0; i < 26; i++)
    {
        cin >> alpha[i];
    }

    alpha[to_lower(s[0]) - 'a'] -= 2;
    res.push_back(to_upper(s[0]));
    if (alpha[to_lower(s[0]) - 'a'] < 0)
    {
        cout << "-1";
        return 0;
    }
    for (int i = 1; i < s.length(); i++)
    {
        char now = to_lower(s[i]);

        if (s[i] != s[i - 1])
        {
            if (now == ' ')
                n--;
            else
            {
                if (s[i - 1] == ' ')
                {
                    alpha[now - 'a'] -= 2;
                    res.push_back(to_upper(s[i]));
                }
                else
                    alpha[now - 'a']--;
            }
        }

        if (alpha[now - 'a'] < 0 || n < 0)
        {
            cout << "-1";
            return 0;
        }
    }

    cout << res;
    return 0;
}