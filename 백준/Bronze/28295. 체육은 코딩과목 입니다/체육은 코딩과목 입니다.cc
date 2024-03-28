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

    int now = 0;

    for (int i = 0; i < 10; i++)
    {
        int a;
        cin >> a;
        if (a == 1)
            now += 1;
        else if (a == 2)
            now += 2;
        else
            now -= 1;
        now += 4;
        now %= 4;
    }

    if (now == 0)
        cout << "N";
    else if (now == 1)
        cout << "E";
    else if (now == 2)
        cout << "S";
    else
        cout << "W";
    return 0;
}