#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (1)
    {
        string s;
        getline(cin,s);

        if (s == "END")
            return 0;

        for (int i = s.length() - 1; i >= 0; i--)
        {
            cout << s[i];
        }
        cout << endl;
    }

    return 0;
}