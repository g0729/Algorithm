#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

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

        vector<int> v(26);
        bool flag = true;
        for (int i = 0; i < s.length(); i++)
        {
            v[s[i] - 'A']++;
            if (v[s[i] - 'A'] % 3 == 0)
            {
                if (i + 1 == s.length() || s[i + 1] != s[i])
                {
                    flag = false;
                    break;
                }
                else
                {
                    i++;
                }
            }
        }

        if (flag)
            cout << "OK";
        else
            cout << "FAKE";
        cout << "\n";
    }
    return 0;
}