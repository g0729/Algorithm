#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int res = 1;
    string s;
    cin >> s;
    for (int i = 1; i < n; i++)
    {
        cin >> s;
        if (s == "0")
        {
        }
        else if (s == "1")
        {
            res += 2;
        }
        else
        {
            res += s.length() + 1;
        }
        res += 2;
    }
    cin >> s;

    if (s == "0")
        res += 1;
    else
        res += s.length() + 2;
    cout << res;
    return 0;
}