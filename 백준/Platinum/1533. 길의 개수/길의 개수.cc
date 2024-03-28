#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000003
#define Matrix vector<vector<ll>>
Matrix MAP(5 * (21), vector<ll>(5 * (21)));
ll n, s, e, d;
Matrix multi(Matrix &a, Matrix &b)
{
    Matrix temp(5 * (21), vector<ll>(5 * (21)));

    for (ll i = 1; i <= 5 * n; i++)
    {
        for (ll j = 1; j <= 5 * n; j++)
        {
            for (ll q = 1; q <= 5 * n; q++)
            {
                temp[i][j] += a[i][q] * b[q][j];
                temp[i][j] = temp[i][j] % MOD;
            }
        }
    }
    return temp;
}
Matrix mypow(Matrix &a, ll cnt)
{
    Matrix temp(5 * (21), vector<ll>(5 * (21)));

    if (cnt == 0)
    {
        for (int i = 1; i <= 5 * n; i++)
        {
            temp[i][i] = 1;
        }
        return temp;
    }
    if (cnt == 1)
        return a;
    temp = mypow(a, cnt / 2);
    temp = multi(temp, temp);
    if (cnt % 2 == 1)
        temp = multi(temp, a);

    return temp;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s >> e >> d;

    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++)
        {
            if (s[j - 1] >= '1')
                MAP[5 * i][5 * j - (s[j - 1] - '0' - 1)] = 1;
        }
        for (int j = 1; j <= 4; j++)
        {
            MAP[5 * (i - 1) + j][5 * (i - 1) + j + 1] = 1;
        }
    }

    Matrix ans = mypow(MAP, d);

    cout << ans[5 * s][5 * e];
    return 0;
}