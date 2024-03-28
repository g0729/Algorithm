#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
ll n, p, q, x, y;
map<ll, ll> ma;
ll divide(ll num)
{
    if (num <= 0)
        return 1;
    else if (ma.find(num) != ma.end())
        return ma[num];
    else
        return ma[num] = divide(num / p - x) + divide(num / q - y);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> p >> q >> x >> y;

    cout << divide(n);
    return 0;
}