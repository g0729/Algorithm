#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int now = 2;

    for (int i = 0; i < n; i++)
    {
        now = 2 * now - 1;
    }

    cout << now * now;
    return 0;
}