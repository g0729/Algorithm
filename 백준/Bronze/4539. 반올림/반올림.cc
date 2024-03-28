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

    int t;
    cin >> t;

    while (t--)
    {
        int a;
        cin >> a;

        for (int i = 1; i * 10 < a; i *= 10)
        {
            int temp = (a % (i * 10)) / i;

            if (temp >= 5)
                a += i * 10;

            a -= a % (i * 10);
        }
        cout<<a<<"\n";
    }
    return 0;
}