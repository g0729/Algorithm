#include <bits/stdc++.h>
using namespace std;
#define lint long long
int n, r, c;
lint N;
lint res = 0;
void dfs(int x, int y, lint size)
{
    if (size==1)
        return;
    if (c > x + size / 2)
    {
        if (r > y + size / 2)
        {
            res += (size*size)/4*3;
            dfs(x + size / 2, y + size / 2, size / 2);
        }
        else
        {
            res += (size*size)/4;
            dfs(x + size / 2, y, size / 2);
        }
    }
    else
    {
        if (r > y + size / 2)
        {
            res += (size*size)/2;
            dfs(x, y + size / 2, size / 2);
        }
        else
        {
            dfs(x, y , size / 2);
        }
    }
}
int main()
{
    cin >> n >> r >> c;
    N = 1;

    for (int i = 0; i < n; i++)
    {
        N *= 2;
    }
    r++;
    c++;

    dfs(0, 0, N);
    cout << res;
}