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
    int n, x, y;
    cin >> n >> x >> y;
    int res = 0;
    int left = 0;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        res += a / x;
        left += max(a - (a / x) * y, 0);
    }

    cout << res << endl
         << left;
    return 0;
}