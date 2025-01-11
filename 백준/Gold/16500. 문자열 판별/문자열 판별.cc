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

    string s;
    int n;
    cin >> s >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<bool> dp(n + 1);
    dp[0] = true;

    for (int i = 1; i <= s.length(); i++)
    {
        for (int j = 0; j < n; j++)
        {
            bool flag = true;
            if (s[i - 1] != v[j].back())
                continue;
            if (v[j].length() > i)
                continue;
            if (!dp[i - v[j].length()])
                continue;
            int start = i - v[j].length();
            for (int k = 0; k < v[j].length(); k++)
            {
                if (s[start + k] != v[j][k])
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
                dp[i] = true;
        }
    }

    cout << dp[s.length()];

    return 0;
}