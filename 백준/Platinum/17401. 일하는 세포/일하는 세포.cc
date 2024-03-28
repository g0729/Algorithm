#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define Matrix vector<vector<ll>>
ll t, n, d;
vector<Matrix> MAP(105, vector<vector<ll>>(21, vector<ll>(21)));

Matrix multi(Matrix &a, Matrix &b)
{
    Matrix temp(n + 1, vector<ll>(n + 1));

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            for (ll q = 0; q < n; q++)
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
    Matrix temp(n + 1, vector<ll>(n + 1));

    if (cnt == 0)
    {
        for (int i = 0; i < n; i++)
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
void print(Matrix &a)
{
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t >> n >> d;

    for (int i = 0; i < n; i++)
    {
        MAP[0][i][i] = 1;
    }

    for (ll i = 1; i <= t; i++)
    {
        ll m;
        cin >> m;
        for (ll j = 0; j < m; j++)
        {
            ll a, b, c;
            cin >> a >> b >> c;
            MAP[i][a - 1][b - 1] = c;
        }
    }

    for (int i = 1; i <= t; i++)
        MAP[0] = multi(MAP[0], MAP[i]);

    MAP[0] = mypow(MAP[0], d / t);
    for (int i = 1; i <= d % t; i++)
        MAP[0] = multi(MAP[0], MAP[i]);

    print(MAP[0]);
    return 0;
}