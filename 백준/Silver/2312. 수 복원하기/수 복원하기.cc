#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
#define MAX 100000

bool isPrime[MAX];

void eratos()
{
    memset(isPrime, true, sizeof(isPrime));

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < MAX; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j < MAX; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    eratos();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 2; i <= n; i++)
        {
            if (isPrime[i])
            {
                int cn = n;
                int cnt = 0;
                while (1)
                {
                    if (cn % i == 0)
                    {
                        cnt++;
                        cn /= i;
                    }
                    else
                        break;
                }
                if(cnt!=0)
                cout << i << " " << cnt << "\n";
            }
        }
    }
    return 0;
}