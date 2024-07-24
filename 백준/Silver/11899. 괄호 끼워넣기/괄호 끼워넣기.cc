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

    string s;
    cin >> s;
    int cnt = 0;
    int res = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ')')
            cnt--;
        else
            cnt++;
        if (cnt == -1)
        {
            res++;
            cnt = 0;
        }
    }

    res += cnt;

    cout << res;
    return 0;
}