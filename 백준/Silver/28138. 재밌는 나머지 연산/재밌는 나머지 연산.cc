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
    ll n, r;
    cin >> n >> r;
    ll temp = n - r;
    ll res = 0;

    for (ll i = 1; i * i <= temp; i++)
    {
        if(temp%i==0)
        {
            if(i>r)
                res+=i;
            if(i*i!=temp&&temp/i>r)
                res+=temp/i;
        }
    }

    cout << res;
    return 0;
}