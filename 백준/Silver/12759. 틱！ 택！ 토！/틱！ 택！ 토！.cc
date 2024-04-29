#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int MAP[3][3];

bool check()
{
    for (int i = 0; i < 3; i++)
    {
        if ((MAP[i][0] == MAP[i][1] && MAP[i][1] == MAP[i][2]) && MAP[i][0] != 0)
            return true;
        if ((MAP[0][i] == MAP[1][i] && MAP[1][i] == MAP[2][i]) && MAP[0][i] != 0)
            return true;
    }
    if ((MAP[0][0] == MAP[1][1] && MAP[1][1] == MAP[2][2]) && MAP[0][0] != 0)
        return true;
    if ((MAP[0][2] == MAP[1][1] && MAP[1][1] == MAP[2][0]) && MAP[0][2] != 0)
        return true;

    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int start;
    cin >> start;

    for (int i = 0; i < 9; i++)
    {
        int a, b;
        cin >> a >> b;
        MAP[a - 1][b - 1] = i % 2 + 1;

        if (check())
        {
            if (i % 2)
                cout << start % 2 + 1;
            else
                cout << start;
            return 0;
        }
    }

    cout << "0";
    return 0;
}