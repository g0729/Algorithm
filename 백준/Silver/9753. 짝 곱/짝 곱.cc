#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

bool isPrime(int n)
{
    if (n <= 1)
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

        bool flag = false;
        while (true)
        {
            for (int i = 2; i * i < n; i++)
            {
                if (n % i == 0 && isPrime(i) && isPrime(n / i))
                {
                    cout << n << "\n";
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
            n++;
        }
    }
    return 0;
}