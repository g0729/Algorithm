#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    set<string> s;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        s.insert(temp);
    }

    int res = 0;

    for (int i = 0; i < m; i++)
    {
        string temp;
        cin >> temp;
        if (s.find(temp) != s.end())
            res++;
    }

    cout << res;
}