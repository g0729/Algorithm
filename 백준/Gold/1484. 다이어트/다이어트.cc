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

    ll g;
    cin >> g;
    ll start, end;
    start = end = 1;
    bool flag = false;
    while (1)
    {
        ll temp = end * end - start * start;
        if (temp == g)
        {
            flag = true;
            cout << end << "\n";
        }
        if (end - start == 1 && temp > g)
            break;
        if (temp > g)
            start++;
        else
            end++;
    }

    if (!flag)
        cout << "-1";
    return 0;
}