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

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        ll res = 0, max = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            if (v[i] > max)
                max = v[i];
            else
                res += max - v[i];
        }

        cout << res << "\n";
    }
    return 0;
}