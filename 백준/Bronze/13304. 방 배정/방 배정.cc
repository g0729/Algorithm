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

    vector<int> v(5);

    int n, k;
    cin >> n >> k;

    while (n--)
    {
        int a, b;
        cin >> b >> a;
        if (a <= 2)
            v[0]++;
        else if (a <= 4)
        {
            if (b == 0)
                v[1]++;
            else
                v[2]++;
        }
        else
        {
            if (b == 0)
                v[3]++;
            else
                v[4]++;
        }
    }
    int res = 0;

    for (int i = 0; i < 5; i++)
    {
        res += (v[i] + k - 1) / k;
    }

    cout << res;
    return 0;
}