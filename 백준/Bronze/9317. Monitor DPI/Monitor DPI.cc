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
    cout.precision(2);

    while (1)
    {
        double a, b, c;
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0)
            break;
        double w, h;
        w = 16 * a / sqrt(337);
        h = 9 * w / 16;
        cout << "Horizontal DPI: " << b / w << "\n";
        cout << "Vertical DPI: " << c / h << "\n";
    }
    return 0;
}