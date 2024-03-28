#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int arr[501];
int sum[501];

bool isPrime(int num)
{
    if (num <= 1)
        return false;
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }

    int res = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (isPrime(j - i + 1))
            {
                if (isPrime(sum[j] - sum[i - 1]))
                    res++;
            }
        }
    }

    cout << res;
    return 0;
}