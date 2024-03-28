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
        int a, b, c;
        cin >> a >> b >> c;

        if (a < b - c)
            cout << "advertise";
        else if (a > b - c)
            cout << "do not advertise";
        else
            cout << "does not matter";
        cout << "\n";
    }
    return 0;
}