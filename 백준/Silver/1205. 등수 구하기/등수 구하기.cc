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

    int n, m, p;
    cin >> n >> m >> p;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int cnt = 0;
    int idx = 1;

    for (int i = 0; i < n; i++)
    {
        if (v[i] > m)
            idx++;
        else if (v[i] < m)
            break;
        cnt++;
    }

    if (cnt == p)
    {
        cout << "-1";
        return 0;
    }
    if (n == 0)
    {
        cout << "1";
        return 0;
    }

    cout << idx;
    return 0;
}