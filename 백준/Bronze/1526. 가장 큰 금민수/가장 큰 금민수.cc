#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

bool check(int n)
{
    string s = to_string(n);

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != '4' && s[i] != '7')
            return false;
    }

    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    while (1)
    {
        if (check(n))
        {
            cout << n;
            break;
        }
        n--;
    }
    return 0;
}