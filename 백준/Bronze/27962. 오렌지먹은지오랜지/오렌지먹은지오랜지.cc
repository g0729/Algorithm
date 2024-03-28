#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

bool check(string &a, string &b)
{
    int cnt = 0;

    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] != b[i])
            cnt++;
    }

    if (cnt >= 2 || cnt == 0)
        return false;

    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    bool flag = false;
    for (int i = 1; i < n; i++)
    {
        string a = s.substr(0, i);
        string b = s.substr(s.length() - i);

        if (check(a, b))
            flag = true;
    }

    if (flag)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}