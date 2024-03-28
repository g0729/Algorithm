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

    int n;
    cin >> n;

    cout << "Gnomes:\n";
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (a < b && b < c)
            cout << "Ordered";
        else if (a > b && b > c)
            cout << "Ordered";
        else
            cout << "Unordered";

        cout << "\n";
    }

    return 0;
}