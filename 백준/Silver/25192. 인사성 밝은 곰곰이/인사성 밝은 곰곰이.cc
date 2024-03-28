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
    int n;
    cin >> n;

    int res = 0;
    set<string> se;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s == "ENTER")
            se.clear();
        else
        {
            if (se.find(s) == se.end())
            {
                res++;
                se.insert(s);
            }
        }
    }

    cout << res;
    return 0;
}