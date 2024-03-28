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

    int a, b, c;
    cin >> a >> b >> c;
    int time = 3600 * a + b * 60 + c;

    int q;
    cin >> q;
    while (q--)
    {
        cin >> a;
        if (a == 2)
        {
            cin >> b;
            time = time - b;
            while (time < 0)
                time += 3600 * 24;
        }
        else if (a == 1)
        {
            cin >> b;
            time = (time + b) % (3600 * 24);
        }
        else
        {
            cout << time / 3600 << " " << (time % 3600) / 60 << " " << time % 60 << "\n";
        }
    }
    return 0;
}