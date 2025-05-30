#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, t;
    cin >> n >> t;
    int res = INF;
    for (int i = 0; i < n; i++)
    {
        int s, l, c;
        cin >> s >> l >> c;

        for (int j = 0; j < c; j++)
        {
            int temp = s + j * l;
            if (temp < t)
                continue;
            res = min(res, temp - t);
            break;
        }
    }

    if (res == INF)
        cout << -1;
    else
        cout << res;
    return 0;
}