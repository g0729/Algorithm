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

    cout << fixed;
    cout.precision(1);
    int t = 1;
    while (1)
    {
        int n;
        cin >> n;
        if (!n)
            break;
        vector<double> v(n);

        for (int i = 0; i < n; i++)
            cin >> v[i];

        cout << "Case " << t << ": ";
        if (n % 2 == 1)
            cout << v[n / 2];
        else
            cout << (v[n / 2 - 1] + v[n / 2]) / 2;
        cout << "\n";
        t++;
    }
    return 0;
}