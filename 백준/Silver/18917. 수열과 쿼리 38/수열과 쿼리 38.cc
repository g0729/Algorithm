#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    ll sum1 = 0, sum2 = 0;

    cin >> n;
    while (n--)
    {
        ll op, num;
        cin >> op;

        if (op == 1)
        {
            cin >> num;
            sum1 += num;
            sum2 ^= num;
        }
        else if (op == 2)
        {
            cin >> num;
            sum1 -= num;
            sum2 ^= num;
        }
        else if (op == 3)
            cout << sum1 << "\n";
        else
            cout << sum2 << "\n";
    }
    return 0;
}