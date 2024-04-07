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
        int k;
        cin >> k;
        vector<int> alpha(26);

        for (int i = 0; i < s.length(); i++)
        {
            alpha[s[i] - 'a']++;
        }

        int res1, res2;
        res1 = 1e9;
        res2 = -1;

        for (int i = 0; i < s.length(); i++)
        {
            if (alpha[s[i] - 'a'] < k)
                continue;

            int temp = 0;
            for (int j = i; j < s.length(); j++)
            {
                if (s[i] == s[j])
                    temp++;
                if (temp == k)
                {
                    res1 = min(res1, j - i + 1);
                    res2 = max(res2, j - i + 1);
                    break;
                }
            }
        }
        if (res1 == 1e9 && res2 == -1)
            cout << "-1";
        else
            cout << res1 << " " << res2;
        cout << "\n";
    }
    return 0;
}