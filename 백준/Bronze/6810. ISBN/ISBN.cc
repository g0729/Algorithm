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

    int n = 91;

    for (int i = 0; i < 3; i++)
    {
        int a;
        cin >> a;
        if (i % 2 == 0)
            n += a;
        else
            n += a * 3;
    }
    cout << "The 1-3-sum is " << n;

    return 0;
}