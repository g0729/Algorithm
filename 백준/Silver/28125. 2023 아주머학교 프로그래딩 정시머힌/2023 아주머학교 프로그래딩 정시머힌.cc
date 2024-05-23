#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int cnt = 0;
        string answer;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '@')
            {
                answer += 'a';
                cnt++;
            }
            else if (s[i] == '[')
            {
                answer += 'c';
                cnt++;
            }
            else if (s[i] == '!')
            {
                answer += 'i';
                cnt++;
            }
            else if (s[i] == ';')
            {
                answer += 'j';
                cnt++;
            }
            else if (s[i] == '^')
            {
                answer += 'n';
                cnt++;
            }
            else if (s[i] == '0')
            {
                answer += 'o';
                cnt++;
            }
            else if (s[i] == '7')
            {
                answer += 't';
                cnt++;
            }
            else if (s[i] == '\\' && s[i + 1] == '\'')
            {
                answer += 'v';
                cnt++;
                i += 1;
            }
            else if (s[i] == '\\' && s[i + 1] == '\\' && s[i + 2] == '\'')
            {
                answer += 'w';
                cnt++;
                i += 2;
            }
            else
            {
                answer += s[i];
            }
        }
        if ((answer.length() + 1) / 2 <= cnt)
            cout << "I don't understand";
        else
            cout << answer;
        cout << "\n";
    }
    return 0;
}