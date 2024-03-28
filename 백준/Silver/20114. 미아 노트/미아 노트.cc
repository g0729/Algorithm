#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, h, w;
    cin >> n >> h >> w;
    vector<string> v(h);

    for (int i = 0; i < h; i++)
    {
        cin >> v[i];
    }

    string res;

    for (int i = 0; i < n; i++)
    {
        char temp = '?';
        for (int j = 0; j < h; j++)
        {
            for (int p = i * w; p < (i + 1) * w; p++)
            {
                if (v[j][p] != '?')
                    temp = v[j][p];
            }
        }
        res.push_back(temp);
    }

    cout << res;
    return 0;
}