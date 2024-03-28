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

    int res = 1e9;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int temp = abs(i) + abs(j);
            bool flag = false;
            int d = v[1] + j - v[0] + i;
            int before = v[1] + j;
            for (int k = 2; k < n; k++)
            {
                int diff = v[k] - before;
                diff -= d;
                if (abs(diff) > 1)
                {
                    flag = true;
                    break;
                }
                temp += abs(diff);
                before = v[k] - diff;
            }
            if (flag)
                continue;
            res = min(res, temp);
        }
    }

    if (res == 1e9)
        cout << "-1";
    else
        cout << res;
    return 0;
}