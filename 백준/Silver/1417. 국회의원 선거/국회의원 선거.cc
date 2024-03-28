#include <bits/stdc++.h>
using namespace std;
#define lint long long

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

    int res = 0;

    while (1)
    {
        int MAX = 0;
        int MAX_i = 0;
        for (int i = 1; i < n; i++)
        {
            if (MAX < v[i])
            {
                MAX = v[i];
                MAX_i = i;
            }
        }

        if (v[0] > MAX)
            break;

        v[MAX_i]--;
        v[0]++;
        res++;
    }

    cout << res;
    return 0;
}