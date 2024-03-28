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

    int n, m;
    cin >> n >> m;

    vector<int> v;

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        vector<int> temp(a);

        for (int j = 0; j < a; j++)
        {
            cin >> temp[j];
        }
        if (a < b)
        {
            v.push_back(1);
            continue;
        }

        sort(temp.begin(), temp.end(), greater<>());

        v.push_back(temp[b - 1]);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        if (m >= v[i])
        {
            m -= v[i];
            res++;
        }
    }

    cout << res;
    return 0;
}