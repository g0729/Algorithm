#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> row(n + 1);
    vector<int> column(m + 1);

    for (int i = 0; i < q; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
            row[b] += c;
        else
            column[b] += c;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << row[i] + column[j] << " ";
        }
        cout << "\n";
    }
    return 0;
}