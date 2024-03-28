#include <bits/stdc++.h>
using namespace std;
#define MAX 2001
int n, m;
int arr[MAX];
bool dp[MAX][MAX];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        dp[i][i] = true;
    }
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i + 1])
            dp[i][i + 1] = true;
    }
    for (int d = 2; d < n; d++)
    {
        for (int start = 1; start + d <= n; start++)
        {
            if (dp[start + 1][start + d - 1] && arr[start] == arr[start + d])
                dp[start][start + d] = true;
        }
    }
    cin >> m;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        cout<<dp[a][b]<<"\n";
    }
}