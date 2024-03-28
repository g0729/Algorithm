#include <bits/stdc++.h>
using namespace std;
#define lint long long
lint pibo[80];
int main()
{
    int n;
    cin >> n;
    pibo[0] = pibo[1] = 1;
    for (int i = 2; i < 80; i++)
    {
        pibo[i] = pibo[i - 1] + pibo[i - 2];
    }
    if (n == 1)
        cout << "4";
    else if (n == 2)
        cout << "6";
    else if (n == 3)
        cout << "10";
    else
    {
        n=n-1;
        lint res = pibo[n] * 3 + pibo[n - 1] * 2 + pibo[n - 2] * 2 + pibo[n - 3];
        cout << res;
    }
}