#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    vector<ll> positive;
    vector<ll> negative;
    cin >> n;
    ll zero, one;
    zero = one = 0;

    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        if (a == 0)
            zero++;
        else if (a == 1)
            one++;
        else if (a > 0)
            positive.push_back(a);
        else
            negative.push_back(a);
    }
    sort(positive.begin(), positive.end(), greater<ll>());
    sort(negative.begin(), negative.end());

    ll answer = 0;

    for (ll i = 0; i + 1 < positive.size(); i += 2)
        answer += positive[i] * positive[i + 1];
    if (positive.size() % 2)
        answer += positive.back();

    for (ll i = 0; i + 1 < negative.size(); i += 2)
        answer += negative[i] * negative[i + 1];
    if (negative.size() % 2 && zero == 0)
        answer += negative.back();

    answer += one;

    cout << answer;
    return 0;
}