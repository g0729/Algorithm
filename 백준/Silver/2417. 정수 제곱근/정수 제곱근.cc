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

    ll a;
    cin >> a;

    ll b = sqrt(a);

    if (b * b < a)
        b += 1;
    cout << b;
    return 0;
}