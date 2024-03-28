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

    while (1)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0)
            break;
        if (abs(a - b) == abs(b - c))
        {
            cout << "AP " << c + (c - b);
        }
        else
        {
            cout << "GP " << c * (c / b);
        }
        cout << "\n";
    }
    return 0;
}