#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000

bool isPrime(int n)
{
    if (n == 1 || n == 0)
        return false;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
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

        vector<int> v(n + 1);
        vector<int> sum(n + 1);

        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];

            sum[i] = sum[i - 1] + v[i];
        }

        bool flag = false;

        for (int d = 1; d < n; d++)
        {
            for (int start = d + 1; start <= n; start++)
            {
                int temp = sum[start] - sum[start - d - 1];

                if (isPrime(temp))
                {
                    flag = true;
                    cout << "Shortest primed subsequence is length " << d + 1 << ": ";
                    for (int i = start - d; i <= start; i++)
                        cout << v[i] << " ";
                    cout << "\n";
                }
                if (flag)
                    break;
            }

            if (flag)
                break;
        }

        if (flag)
            continue;

        cout << "This sequence is anti-primed.\n";
    }
    return 0;
}