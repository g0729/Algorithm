#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dp[5002];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;
    cin >> n >> s;

    dp[1] = 1;

    for (int i = 2; i <= s.length(); i++)
    {
        dp[i] = dp[i - 1] + 1;
        if (s[i - 1] == '0')
        {
            if (s[i - 2] != '0')
                dp[i] = dp[i - 2] + 1;
            else
                dp[i] = dp[i - 3] + 1;
        }
        string temp;
        temp.push_back(s[i - 1]);
        for (int j = i - 1; j > 0 && j > i - 3; j--)
        {
            string temp2;
            temp2.push_back(s[j - 1]);
            temp = temp2 + temp;
            if (temp2 == "0")
                continue;
            int temp3 = stoi(temp);
            if (temp3 <= 641)
                dp[i] = min(dp[i], dp[j - 1] + 1);
        }
    }

    cout << dp[n];
    return 0;
}