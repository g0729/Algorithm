#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
ll dx[] = {1, -1, 0, 0};
ll dy[] = {0, 0, 1, -1};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;

    if (n <= 4)
    {
        cout << "4";
        return 0;
    }
    ll a = sqrt(n);
    if (a * a == n)
        cout << (a - 1) * 4;
    else if (a * (a + 1) >= n)
        cout
            << (4 * a - 2);
    else
        cout << (4 * a);

    return 0;
}