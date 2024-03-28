#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int m;
    cin >> m;
    vector<int> v2(m);
    for (int i = 0; i < m; i++)
    {
        cin >> v2[i];
    }

    int a_idx, b_idx;
    a_idx = b_idx = -1;
    vector<int> res;
    while (1)
    {
        int val = 0;
        int na, nb;

        for (int i = a_idx + 1; i < n; i++)
        {
            for (int j = b_idx + 1; j < m; j++)
            {
                if (v[i] == v2[j])
                {
                    if (val < v[i])
                    {
                        val = v[i];
                        na = i;
                        nb = j;
                    }
                }
            }
        }

        if (val == 0)
            break;
        res.push_back(val);
        a_idx = na;
        b_idx = nb;
    }

    cout << res.size() << "\n";

    for (auto it : res)
        cout << it << " ";
    return 0;
}