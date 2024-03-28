#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 3; i++)
    {
        int a, b, c, A, B, C;
        cin >> a >> b >> c >> A >> B >> C;
        int sum = 3600 * A + 60 * B + C - (3600 * a + 60 * b + c);
        cout << sum / 3600 << " " << (sum % 3600) / 60 << " " << sum % 60 << endl;
    }

    return 0;
}