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

    int n, m;
    cin >> n;
    vector<string> v(n);
    set<string> se;
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        se.insert(v[i]);
        if (v[i] == "?")
            idx = i;
    }

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        if(n==1)
        {
            cout<<s;
            return 0;
        }
        if (se.find(s) != se.end())
            continue;
        if (idx == 0)
        {
            if (v[idx + 1].front() == s.back())
            {
                cout << s;
                return 0;
            }
        }
        else if (idx == n - 1)
        {
            if (v[idx - 1].back() == s.front())
            {
                cout << s;
                return 0;
            }
        }
        else
        {
            if (v[idx - 1].back() == s.front() && v[idx + 1].front() == s.back())
            {
                cout << s;
                return 0;
            }
        }
    }

    return 0;
}