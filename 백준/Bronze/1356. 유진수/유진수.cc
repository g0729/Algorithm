#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

bool cal(string &a, string &b)
{
    int A, B;
    A = a[0]-'0';
    B = b[0]-'0';

    for (int i = 1; i < a.length(); i++)
    {
        A *= a[i]-'0';
    }

    for (int i = 1; i < b.length(); i++)
    {
        B *= b[i]-'0';
    }

    if (A == B)
        return true;
    else
        return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    bool flag = false;

    for (int i = 1; i < s.length(); i++)
    {
        string a = s.substr(0, i);
        string b = s.substr(i);

        if (cal(a, b))
        {
            flag = true;
            break;
        }
    }

    if (flag)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}