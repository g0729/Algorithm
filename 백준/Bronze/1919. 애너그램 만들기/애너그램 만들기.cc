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

    string a, b;
    cin >> a >> b;
    vector<int> c(26), d(26);
    for (int i = 0; i < a.length(); i++)
    {
        c[a[i] - 'a']++;
    }
    for (int i = 0; i < b.length(); i++)
    {
        d[b[i] - 'a']++;
    }

    int res = 0;
    for (int i = 0; i < 26; i++)
    {
        res += abs(c[i] - d[i]);
    }

    cout << res;

    return 0;
}