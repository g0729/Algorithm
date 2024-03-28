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

    string a, b, c;
    cin >> a >> b >> c;

    if (b == "*")
    {
        cout << "1";

        for (int i = 0; i < a.length() + c.length() - 2; i++)
        {
            cout << "0";
        }
    }
    else
    {
        if (a.length() == c.length())
        {
            cout << "2";
            for (int i = 0; i < a.length() - 1; i++)
            {
                cout << "0";
            }
        }
        else
        {
            cout << "1";
            for (int i = 0; i < abs((int)a.length() - (int)c.length()) - 1; i++)
            {
                cout << "0";
            }
            cout << "1";
            for (int i = 0; i < min(a.length(), c.length()) - 1; i++)
            {
                cout << "0";
            }
        }
    }
    return 0;
}