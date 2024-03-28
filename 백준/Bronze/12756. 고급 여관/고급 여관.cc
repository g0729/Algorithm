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

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int temp1 = (d + a - 1) / a;
    int temp2 = (b + c - 1) / c;

    if (temp1 == temp2)
    {
        cout << "DRAW";
        return 0;
    }

    char e = temp1 < temp2 ? 'A' : 'B';

    cout << "PLAYER " << e;

    return 0;
}