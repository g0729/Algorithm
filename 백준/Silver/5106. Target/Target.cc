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
    while (1)
    {
        int n;
        cin >> n;
        if (!n)
            break;
        vector<int> alpha(26);

        string res;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            if (s.length() == 9)
                res = s;
            vector<bool> redun(26);
            for (int j = 0; j < s.length(); j++)
            {
                if (!redun[s[j] - 'a'])
                {
                    redun[s[j] - 'a'] = true;
                    alpha[s[j] - 'a']++;
                }
            }
        }
        char c;
        for (int i = 0; i < 26; i++)
        {
            if (alpha[i] == n)
                c = i + 'a';
        }
        sort(res.begin(), res.end());

        bool flag = false;
        string res2;
        for (int i = 0; i < 9; i++)
        {
            if (!flag && res[i] == c)
            {
                flag = true;
                continue;
            }
            res2.push_back(res[i] - 'a' + 'A');
        }
        for (int i = 0; i < 4; i++)
        {
            cout << res2[i] << " ";
        }
        c = c - 'a' + 'A';
        cout << c << " ";
        for (int i = 4; i < 8; i++)
        {
            cout << res2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}   