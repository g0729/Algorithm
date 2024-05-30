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
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        if (s.length() > 10)
            continue;
        int cnt[2] = {
            0,
        };
        bool flag = false;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
                cnt[0]++;
            else if (s[i] >= 'A' && s[i] <= 'Z')
                cnt[1]++;
            if (!(s[i] >= '0' && s[i] <= '9'))
                flag = true;
        }
        if (!flag)
            continue;
        if (cnt[0] < cnt[1])
            continue;
        cout << s;
    }
    return 0;
}
