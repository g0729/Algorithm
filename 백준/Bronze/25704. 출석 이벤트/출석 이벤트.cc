#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

int min(int a,double b)
{
    if(a>b)
        return b;
    else
        return a;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, p;
    cin >> n >> p;

    int res = p;

    if (n >= 5)
        res = min(res, max(0, p - 500));
    if (n >= 10)
        res = min(res, p * 0.9);
    if (n >= 15)
        res = min(res, max(0, p - 2000));
    if (n >= 20)
        res = min(res, p * 0.75);

    cout << res;
    return 0;
}