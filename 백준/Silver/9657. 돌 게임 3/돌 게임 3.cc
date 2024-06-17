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

    int n;
    cin >> n;
    vector<int> dp(1001);
    dp[2] = 1;
    for (int i = 5; i <= n; i++)
    {
        if (dp[i - 1] == 0 && dp[i - 3] == 0 && dp[i - 4] == 0)
            dp[i] = 1;
        else
            dp[i] = 0;
    }

    if (dp[n] == 0)
        cout << "SK";
    else
        cout << "CY";
    return 0;
}