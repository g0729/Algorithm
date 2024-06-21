#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int weights[2000][2000];
int save[2000][2000];
int output[2000][2000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
            weights[i][j] = s[j] - '0';
    }

    for (int i = 0; i < n; i++)
        output[i][0] = weights[i][0];

    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp = 0;

            for (int k = max(j - 1, 0); k <= min(j + 1, n - 1); k++)
                temp = max(temp, output[k][i - 1]);

            save[j][i] = temp;
            output[j][i] = temp + weights[j][i];
        }
    }

    int answer = 0;
    for (int i = 0; i < n; i++)
        answer = max(answer, save[i][m - 1]);

    cout << answer;

    return 0;
}