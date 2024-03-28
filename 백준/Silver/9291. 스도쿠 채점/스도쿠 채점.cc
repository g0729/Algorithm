#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int MAP[9][9];

bool check(int x, int y)
{
    vector<int> v(10);
    for (int i = x; i < x + 3; i++)
    {
        for (int j = y; j < y + 3; j++)
        {
            v[MAP[i][j]]++;
            if (v[MAP[i][j]] >= 2)
                return false;
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    int idx = 1;
    while (t--)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cin >> MAP[i][j];
            }
        }

        bool flag = true;
        for (int i = 0; i < 9; i++)
        {
            vector<int> v1(10), v2(10);
            for (int j = 0; j < 9; j++)
            {
                v1[MAP[i][j]]++;
                v2[MAP[j][i]]++;
                if (v1[MAP[i][j]] >= 2 || v2[MAP[i][j]] >= 2)
                    flag = false;
            }
        }
        for (int i = 0; i <= 7; i += 3)
        {
            for (int j = 0; j < 7; j += 3)
            {
                if (!check(i, j))
                    flag = false;
            }
        }

        cout << "Case " << idx << ": ";
        if (flag)
            cout << "CORRECT";
        else
            cout << "INCORRECT";
        cout << "\n";
        idx++;
    }
    return 0;
}