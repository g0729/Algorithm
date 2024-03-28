#include <bits/stdc++.h>
using namespace std;
#define MAX 987654321
#define lint long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long a, b;

    cin >> a >> b;

    long long res = (a + b) * (b - a + 1) / 2;

    if (b < a)
    {
        res = (a + b) * (a - b + 1) / 2;
    }
    cout << res;
    return 0;
}