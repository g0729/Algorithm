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
    int n, m;
    cin >> n >> m;
    while (n--)
    {
        string s;
        cin >> s;
        int now = -1;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'c')
                now = 0;
            cout << now << " ";
            if (now != -1)
                now++;
        }
        cout << "\n";
    }

    return 0;
}