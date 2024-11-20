#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    for (int i = 0; i < s.length() - 1 && m; i++)
    {
        if (s[i] == '0')
            continue;
        int needs = 10 - (s[i] - '0');
        if (needs <= m)
        {
            m -= needs;
            s[i] = '0';
        }
    }

    if (m)
        s.back() = (s.back() - '0' + m) % 10 + '0';
    cout << s;

    return 0;
}