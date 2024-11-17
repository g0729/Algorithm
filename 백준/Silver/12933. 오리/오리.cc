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
    vector<int> v(4);
    string s;
    cin >> s;

    int res = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'q')
        {
            v[0]++;
        }
        else if (s[i] == 'u')
        {
            if (v[0] == 0)
            {
                cout << "-1";
                return 0;
            }
            v[0] -= 1;
            v[1] += 1;
        }
        else if (s[i] == 'a')
        {
            if (v[1] == 0)
            {
                cout << "-1";
                return 0;
            }
            v[1] -= 1;
            v[2] += 1;
        }
        else if (s[i] == 'c')
        {
            if (v[2] == 0)
            {
                cout << "-1";
                return 0;
            }
            v[2] -= 1;
            v[3] += 1;
        }
        else if (s[i] == 'k')
        {
            if (v[3] == 0)
            {
                cout << "-1";
                return 0;
            }
            v[3] -= 1;
        }
        int sum = 0;
        for (int j = 0; j < 4; j++)
        {
            sum += v[j];
        }
        res = max(res, sum);
    }
    for (int i = 0; i < 4; i++)
    {
        if (v[i])
        {
            cout << "-1";
            return 0;
        }
    }

    cout << res;
    return 0;
}