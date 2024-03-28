#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout.tie(0);
    while (1)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;
        int sum = 0;
        for (int i = 0; i <= n; i++)
        {
            sum += i;
        }

        cout << sum << "\n";
    }

    return 0;
}