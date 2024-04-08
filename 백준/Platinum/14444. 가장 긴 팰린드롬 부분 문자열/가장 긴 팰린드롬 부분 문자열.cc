#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int A[MAX * 2 + 2];

int f(string &s)
{
    int r, p;
    r = p = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (i <= r)
            A[i] = min(A[2 * p - i], r - i);
        else
            A[i] = 0;
        while (i - A[i] - 1 >= 0 && i + A[i] + 1 < s.length() && s[i - A[i] - 1] == s[i + A[i] + 1])
            A[i]++;

        if (r < i + A[i])
        {
            r = i + A[i];
            p = i;
        }
    }
    int res = 0;
    for (int i = 0; i < s.length(); i++)
    {
        res = max(res, A[i]);
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    string S;
    for (int i = 0; i < s.length(); i++)
    {
        S += "#";
        S += s[i];
    }
    S += "#";
    cout << f(S);
    return 0;
}