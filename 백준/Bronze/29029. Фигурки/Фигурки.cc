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
    vector<int> v(4);

    string s;
    cin >> s;

    for (auto it : s)
    {
        if (it == 'N')
            v[0]++;
        else if (it == 'S')
            v[1]++;
        else if (it == 'E')
            v[2]++;
        else
            v[3]++;
    }
    int res = 1e9;
    for (int i = 0; i < 4; i++)
    {
        res = min(res, n - v[i]);
    }
    cout << res;
    return 0;
}
