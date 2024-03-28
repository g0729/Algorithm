#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unordered_set<string> Set;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        Set.insert(s);
    }

    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;

        int start;
        start = 0;
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] == ',')
            {
                string temp = s.substr(start, j - start);
                Set.erase(temp);
                start = j + 1;
            }
            else if (j == s.length() - 1)
            {
                string temp = s.substr(start);
                Set.erase(temp);
            }
        }

        cout << Set.size() << "\n";
    }

    return 0;
}