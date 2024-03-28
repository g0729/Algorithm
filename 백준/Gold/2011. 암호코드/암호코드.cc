#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000
int dp[5001];
int main()
{
    string s;
    cin >> s;

    dp[0] = 1;
    dp[1] = 1;
    if(s[0]=='0')
    {
        cout<<"0";
        return 0;
    }
    for (int i = 1; i < s.length(); i++)
    {
        char temp[3];
        temp[0] = s[i - 1];
        temp[1] = s[i];
        int temp2 = atoi(temp);
        if (temp[1] == '0')
        {
            if (temp2 == 10 || temp2 == 20)
            {
                dp[i + 1] = dp[i - 1] ;
                continue;
            }
            else
            {
                cout<<"0";
                return 0;
            }
        }
        if (temp2 > 10 && temp2 < 27)
        {
            dp[i + 1] = (dp[i] + dp[i - 1]) % MOD;
        }
        else
            dp[i + 1] = dp[i];
    }
    cout << dp[s.length()] % MOD;
}