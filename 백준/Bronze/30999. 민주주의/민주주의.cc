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

    int n, m;
    cin >> n >> m;

    int res = 0;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        int cnt = 0;

        for (int i = 0; i < m; i++)
        {
            cnt += s[i] == 'O' ? 1 : 0;
        }

        res += cnt > m / 2 ? 1 : 0;
    }

    cout << res;
    return 0;
}