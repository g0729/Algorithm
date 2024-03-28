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

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt[2] = {
        0,
    };
    bool flag = false;
    n = min(n, k);
    for (int j = 0; j < n; j++)
    {

        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];

            if (c == 'U')
                cnt[0]--;
            else if (c == 'D')
                cnt[0]++;
            else if (c == 'R')
                cnt[1]--;
            else
                cnt[1]++;

            if (cnt[0] == 0 && cnt[1] == 0)
                flag = true;
        }
    }
    if (flag)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}