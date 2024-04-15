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
        int n, m;
        cin >> n >> m;
        int res = 0;
        vector<vector<char>> MAP(n, vector<char>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> MAP[i][j];
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (MAP[i][j] == '>' && j + 2 < m)
                {
                    if (MAP[i][j + 1] == 'o' && MAP[i][j + 2] == '<')
                        res++;
                }
                else if (MAP[i][j] == 'v' && i + 2 < n)
                {
                    if (MAP[i + 1][j] == 'o' && MAP[i + 2][j] == '^')
                        res++;
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}
