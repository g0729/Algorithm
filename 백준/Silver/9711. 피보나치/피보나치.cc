#include <bits/stdc++.h>
using namespace std;
#define lint long long
#define matrix vector<vector<lint>>
lint MOD;
matrix operator*(const matrix &a, const matrix &b)
{
    int k = a.size();
    matrix c(k, vector<lint>(k));
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            for (int q = 0; q < k; q++)
            {
                c[i][j] += a[i][q] * b[q][j];
            }
            c[i][j] = c[i][j] % MOD;
        }
    }
    return c;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n >> MOD;

        matrix res = {{1, 0}, {0, 1}};
        matrix temp = {{1, 1}, {1, 0}};
        while (n > 0)
        {
            if (n % 2 == 1)
            {
                res = res * temp;
            }
            temp = temp * temp;
            n /= 2;
        }
        cout << "Case #" << i << ": " << res[0][1] << "\n";
    }
}