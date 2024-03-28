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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> v(2);

        for (int i = 0; i < n; i++)
        {
            char a, b;
            cin >> a >> b;

            if (a == 'R')
            {
                if (b == 'S')
                    v[0]++;
                else if (b == 'P')
                    v[1]++;
            }
            else if (a == 'S')
            {
                if (b == 'R')
                    v[1]++;
                else if (b == 'P')
                    v[0]++;
            }
            else if (a == 'P')
            {
                if (b == 'R')
                    v[0]++;
                else if (b == 'S')
                    v[1]++;
            }
        }
        if (v[1] == v[0])
            cout << "TIE";
        else if (v[0] > v[1])
            cout << "Player 1";
        else
            cout << "Player 2";
        cout << "\n";
    }
    return 0;
}
