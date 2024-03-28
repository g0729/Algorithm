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
    int res = t;
    while (t--)
    {
        string s;
        cin >> s;
        vector<int> alpha(26);
        for (int i = 0; i < s.length(); i++)
        {
            alpha[s[i] - 'a']++;
            if (alpha[s[i] - 'a'] >= 2 && s[i] != s[i - 1])
            {
                res--;
                break;
            }
        }
    }
    cout << res;
    return 0;
}