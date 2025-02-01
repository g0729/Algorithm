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
    int n;
    string s;
    cin >> n >> s;
    vector<int> v(2);

    char now = s[0];

    for (int i = 1; i < s.length(); i++)
    {
        if (now != s[i])
        {
            v[now == 'B' ? 0 : 1]++;
            now = s[i];
        }
    }
    v[now == 'B' ? 0 : 1]++;

    cout << min(v[0], v[1]) + 1;

    return 0;
}