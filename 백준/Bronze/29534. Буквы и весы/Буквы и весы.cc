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

    int n;
    string s;
    cin >> n >> s;
    if (s.length() > n)
        cout << "Impossible";
    else
    {
        int res = 0;
        for (int i = 0; i < s.length(); i++)
        {
            res += s[i] - 'a' + 1;
        }

        cout << res;
    }
    return 0;
}