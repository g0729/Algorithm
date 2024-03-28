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

    int n;
    cin >> n;

    int res = 0;
    int value = 0;
    for (int i = 1; i <= n; i++)
    {
        vector<int> v(5);
        for (int j = 0; j < 5; j++)
        {
            cin >> v[j];
        }
        for (int j = 0; j < 4; j++)
        {
            for (int k = j + 1; k < 5; k++)
            {
                int sum = 0;
                for (int p = 0; p < 5; p++)
                {
                    if (p == j || p == k)
                        continue;
                    sum += v[p];
                }
                sum %= 10;
                if (sum >= value)
                {
                    value = sum;
                    res = i;
                }
            }
        }
    }

    cout << res;

    return 0;
}