#include<bits/stdc++.h>
using namespace std;
long long A, B;
int res = 100000;
void dfs(long long a, int cnt)
{
    if (a > B)
        return;
    if (a == B)
    {
        res = min(res, cnt);
        return;
    }
    dfs(10 * a + 1, cnt + 1);
    dfs(a * 2, cnt + 1);
}
int main()
{
    cin >> A >> B;
    dfs(A, 1);
    if (res == 100000)
    {
        cout << "-1";
    }
    else
    cout << res;
}