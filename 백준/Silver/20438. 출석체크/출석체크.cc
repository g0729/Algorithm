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
    int n, k, q, m;
    cin >> n >> k >> q >> m;
    set<int> se;
    vector<int> attend(n + 3, 1);
    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        se.insert(a);
    }

    for (int i = 0; i < q; i++)
    {
        int a;
        cin >> a;
        if (se.find(a) != se.end())
            continue;
        int idx = a;
        while (idx <= n + 2)
        {
            attend[idx] = 0;
            idx += a;
        }
    }

    for (auto it : se)
        attend[it] = 1;

    vector<int> acc(n + 3);

    for (int i = 1; i <= n + 2; i++)
        acc[i] = acc[i - 1] + attend[i];

    for (int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;
        cout << acc[e] - acc[s - 1] << "\n";
    }

    return 0;
}