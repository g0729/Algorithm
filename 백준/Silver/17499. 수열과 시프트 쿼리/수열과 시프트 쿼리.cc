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
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    int offset = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;

        if (a == 1)
        {
            int c;
            cin >> c;
            v[(offset + b - 1) % n] += c;
        }
        else if (a == 2)
        {
            offset = ((offset - b) % n + n) % n;
        }
        else if (a == 3)
        {
            offset = (offset + b) % n;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int cur = (i + offset) % n;
        cout << v[cur] << " ";
    }

    return 0;
}